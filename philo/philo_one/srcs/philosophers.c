/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:12:44 by memartin          #+#    #+#             */
/*   Updated: 2020/12/06 18:20:27 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		check_dead(t_philo *philo)
{
	int		ret;

	ret = FALSE;
	if (philo->param->b_dead)
		ret = TRUE;
	return (ret);
}

static void		take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork_m);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->r_fork_m);
		return ;
	}
	display_state(philo, " has taken a fork\n");
	pthread_mutex_lock(philo->l_fork_m);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->r_fork_m);
		pthread_mutex_unlock(philo->l_fork_m);
		return ;
	}
	display_state(philo, " has taken a fork\n");
}

static void		eat(t_philo *philo)
{
	pthread_mutex_lock(philo->eating_death_m);
	if (philo->param->b_dead)
	{
		pthread_mutex_unlock(philo->eating_death_m);
		pthread_mutex_unlock(philo->r_fork_m);
		pthread_mutex_unlock(philo->l_fork_m);
		return ;
	}
	philo->nb_meal++;
	pthread_mutex_unlock(philo->eating_death_m);
	display_state(philo, " is eating\n");
	ft_usleep(philo->param->time_to_eat);
	gettimeofday(&philo->time_last_meal, NULL);
	pthread_mutex_unlock(philo->r_fork_m);
	pthread_mutex_unlock(philo->l_fork_m);
}

void			*routine(void *arg)
{
	t_philo		*philo;
	int			first;

	philo = arg;
	first = TRUE;
	if (philo->nb % 2 == 0)
		ft_usleep(200);
	while (philo->nb_meal < philo->param->nb_meal_needed
		&& !check_dead(philo))
	{
		if (!first)
		{
			display_state(philo, " is sleeping\n");
			ft_usleep(philo->param->time_to_sleep);
			if (check_dead(philo))
				return (NULL);
			display_state(philo, " is thinking\n");
		}
		first = FALSE;
		take_fork(philo);
		if (check_dead(philo))
			return (NULL);
		eat(philo);
	}
	return (NULL);
}
