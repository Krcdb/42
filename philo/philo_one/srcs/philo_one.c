/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:03:34 by memartin          #+#    #+#             */
/*   Updated: 2020/12/07 16:23:50 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		start_philo(t_philo_one *data)
{
	size_t		i;
	t_philo		*tmp;
	pthread_t	*threads;

	if (!(threads =
		(pthread_t*)malloc(sizeof(pthread_t) * data->param->nb_philo)))
		return (FAILURE);
	i = 0;
	tmp = data->philo;
	gettimeofday(&data->param->time_start, NULL);
	while (tmp)
	{
		tmp->time_last_meal = data->param->time_start;
		if (pthread_create(&threads[i], NULL, &routine, tmp))
			return (FAILURE);
		tmp = tmp->next;
		i++;
	}
	supervisor(data);
	i = 0;
	while (i < data->param->nb_philo)
		pthread_join(threads[i++], NULL);
	free(threads);
	return (SUCCES);
}

int				main(int ac, char **av)
{
	t_philo_one	*data;

	data = NULL;
	if (ac < 5 || ac > 6)
		return (display_error("bad arguments\n") && clear_data(data));
	if (!(data = (t_philo_one*)malloc(sizeof(t_philo_one))))
		return (display_error("malloc error\n") && clear_data(data));
	data->param = NULL;
	data->philo = NULL;
	if (!(data->param = (t_parameters*)malloc(sizeof(t_parameters))))
		return (display_error("malloc error\n") && clear_data(data));
	if (!init_param(data->param, av, ac))
		return (display_error("bad arguments\n") && clear_data(data));
	if (!init_philo(data))
		return (display_error("init philo error\n") && clear_data(data));
	if (!start_philo(data))
		return (display_error("something went wrong\n") && clear_data(data));
	clear_data(data);
	return (0);
}
