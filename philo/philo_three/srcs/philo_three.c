/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:11:40 by memartin          #+#    #+#             */
/*   Updated: 2020/12/09 12:00:26 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void		fork_philo(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, supervisor, philo))
		exit(1);
	pthread_detach(thread);
	routine(philo);
	exit(0);
}

static int		start_philo(t_philo_three *data)
{
	size_t		i;
	t_philo		*tmp;
	pthread_t	thread;

	i = 0;
	tmp = data->philo;
	gettimeofday(&data->param->time_start, NULL);
	while (tmp)
	{
		tmp->time_last_meal = data->param->time_start;
		data->param->pids[i] = fork();
		if (data->param->pids[i] < 0)
			return (FAILURE);
		else if (data->param->pids[i] == 0)
			fork_philo(tmp);
		tmp = tmp->next;
		i++;
	}
	if (pthread_create(&thread, NULL, main_supervisor, data))
		return (FAILURE);
	pthread_detach(thread);
	kill_all(data->param);
	return (SUCCES);
}

static int		init_sem(t_parameters *param)
{
	sem_unlink("/display");
	sem_unlink("/fork");
	sem_unlink("/dead");
	sem_unlink("/first_dead");
	sem_unlink("/finished");
	param->display_s = sem_open("/display", O_CREAT, S_IRWXU | S_IRWXO, 1);
	param->dead_s = sem_open("/dead", O_CREAT, S_IRWXU | S_IRWXO, 0);
	param->first_dead_s =
		sem_open("/first_dead", O_CREAT, S_IRWXU | S_IRWXO, 1);
	param->finished_s = sem_open("/finished", O_CREAT, S_IRWXU | S_IRWXO, 0);
	param->fork_s =
		sem_open("/fork", O_CREAT, S_IRWXU | S_IRWXO, param->nb_philo);
	if (param->display_s == SEM_FAILED || param->fork_s == SEM_FAILED
		|| param->dead_s == SEM_FAILED || param->finished_s == SEM_FAILED
		|| param->first_dead_s == SEM_FAILED)
		return (FAILURE);
	if (!(param->pids = (int*)malloc(sizeof(int) * param->nb_philo)))
		return (FAILURE);
	return (SUCCES);
}

int				main(int ac, char **av)
{
	t_philo_three	*data;

	data = NULL;
	if (ac < 5 || ac > 6)
		return (display_error("bad arguments\n") && clear_data(data));
	if (!(data = (t_philo_three*)malloc(sizeof(t_philo_three))))
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
