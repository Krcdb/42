/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:17:33 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 16:23:27 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		start_philo(t_philo_two *data)
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

static int		init_sem(t_parameters *param)
{
	sem_unlink("/display");
	sem_unlink("/fork");
	param->display_s = sem_open("/display", O_CREAT, S_IRWXU | S_IRWXO, 1);
	param->fork_s = sem_open("/fork", O_CREAT, S_IRWXU | S_IRWXO,
		param->nb_philo);
	if (param->display_s == SEM_FAILED || param->fork_s == SEM_FAILED)
		return (FAILURE);
	return (SUCCES);
}

int				main(int ac, char **av)
{
	t_philo_two	*data;

	data = NULL;
	if (ac < 5 || ac > 6)
		return (display_error("bad arguments\n") && clear_data(data));
	if (!(data = (t_philo_two*)malloc(sizeof(t_philo_two))))
		return (display_error("malloc error\n") && clear_data(data));
	data->param = NULL;
	data->philo = NULL;
	if (!(data->param = (t_parameters*)malloc(sizeof(t_parameters))))
		return (display_error("malloc error\n") && clear_data(data));
	if (!init_param(data->param, av, ac) || !init_sem(data->param))
		return (display_error("bad arguments\n") && clear_data(data));
	if (!init_philo(data))
		return (display_error("init philo error\n") && clear_data(data));
	if (!start_philo(data))
		return (display_error("something went wrong\n") && clear_data(data));
	clear_data(data);
	return (0);
}
