/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:14:44 by memartin          #+#    #+#             */
/*   Updated: 2020/07/29 15:32:59 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		check_args(int ac, char **av)
{
	if (!is_full_digit(av[1]) || !is_full_digit(av[2]) || !is_full_digit(av[3])
		|| !is_full_digit(av[4]))
		return (0);
	if (ac == 6 && !is_full_digit(av[5]))
		return (0);
	return (1);
}

static int		init_data(t_data *data, int ac, char **av)
{
	data->n_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->m_limit = 0;
	if (!check_args(ac, av))
		return (0);
	data->n_philo = atoi_boi(av[1]);
	data->time_to_die = atoi_boi(av[2]);
	data->time_to_eat = atoi_boi(av[3]);
	data->time_to_sleep = atoi_boi(av[4]);
	if (ac == 6)
		data->m_limit = atoi_boi(av[5]);
	gettimeofday(&data->time, NULL);
	if (data->time_to_die > 0 && data->time_to_die > 0 && data->time_to_die > 0
		&& data->n_philo > 1)
		return (1);
	return (0);
}

void			print_data(t_data *data)
{
	printf("nb_philo : %d | die : %d ms | eat : %d ms | sleep : %d ms | limit : %d\n", data->n_philo, data->time_to_die, data->time_to_eat,data->time_to_sleep, data->m_limit);
	printf("time : %ld.%ld", data->time.tv_sec, data->time.tv_usec);
}

int				main(int ac, char **av)
{	
	t_data		data;

	if ((ac != 5 && ac != 6) || !init_data(&data, ac, av))
	{
		print_str("arg error\n");
		return (0);
	}
	print_data(&data);

	return (0);
}
