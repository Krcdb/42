/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:12:44 by memartin          #+#    #+#             */
/*   Updated: 2020/12/12 13:49:02 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void		take_fork(t_philo *philo)
{
	sem_wait(philo->param->fork_s);
	display_state(philo, " has taken a fork\n");
	sem_wait(philo->param->fork_s);
	display_state(philo, " has taken a fork\n");
}

static void		eat(t_philo *philo)
{
	sem_wait(philo->eating_death_s);
	philo->nb_meal++;
	sem_post(philo->eating_death_s);
	display_state(philo, " is eating\n");
	ft_usleep(philo->param->time_to_eat);
	gettimeofday(&philo->time_last_meal, NULL);
	sem_post(philo->param->fork_s);
	sem_post(philo->param->fork_s);
}

static void		*death_monitor(void *arg)
{
	t_philo		*philo;

	philo = arg;
	sem_wait(philo->param->dead_s);
	sem_post(philo->param->dead_s);
	exit(0);
}

void			*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	thread;

	philo = arg;
	if (philo->nb % 2 == 0)
		ft_usleep(200);
	if (pthread_create(&thread, NULL, death_monitor, philo))
		exit(1);
	pthread_detach(thread);
	while (philo->nb_meal < philo->param->nb_meal_needed)
	{
		take_fork(philo);
		eat(philo);
		display_state(philo, " is sleeping\n");
		ft_usleep(philo->param->time_to_sleep);
		display_state(philo, " is thinking\n");
	}
	sem_post(philo->param->finished_s);
	return (NULL);
}
