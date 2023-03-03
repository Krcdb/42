/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:05:56 by memartin          #+#    #+#             */
/*   Updated: 2020/12/09 12:31:21 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			*main_supervisor(void *arg)
{
	t_philo_three		*data;

	data = arg;
	sem_wait(data->param->dead_s);
	data->param->b_dead = TRUE;
	sem_post(data->param->dead_s);
	sem_post(data->param->finished_s);
	return (0);
}

void			kill_all(t_parameters *param)
{
	size_t		i;

	i = 0;
	sem_wait(param->finished_s);
	if (!param->b_dead)
	{
		while (i < param->nb_philo)
			waitpid(param->pids[i++], NULL, 0);
	}
	else
	{
		while (i < param->nb_philo)
			kill(param->pids[i++], SIGTERM);
	}
}

void			*supervisor(void *arg)
{
	t_philo		*philo;

	philo = arg;
	while (1)
	{
		ft_usleep(100);
		sem_wait(philo->eating_death_s);
		if (get_time_us(philo->time_last_meal) >
			philo->param->time_to_die)
		{
			sem_wait(philo->param->first_dead_s);
			display_state(philo, " died\n");
			sem_post(philo->param->dead_s);
			philo->param->b_dead = TRUE;
			sem_post(philo->eating_death_s);
			return (NULL);
		}
		sem_post(philo->eating_death_s);
	}
}
