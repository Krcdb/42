/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:12:44 by memartin          #+#    #+#             */
/*   Updated: 2020/12/07 11:33:22 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		check_dead(t_philo *philo)
{
	int		ret;

	ret = FALSE;
	sem_wait(philo->eating_death_s);
	if (philo->param->b_dead)
		ret = TRUE;
	sem_post(philo->eating_death_s);
	return (ret);
}

static void		take_fork(t_philo *philo)
{
	sem_wait(philo->param->fork_s);
	if (check_dead(philo))
	{
		sem_post(philo->param->fork_s);
		return ;
	}
	display_state(philo, " has taken a fork\n");
	sem_wait(philo->param->fork_s);
	if (check_dead(philo))
	{
		sem_post(philo->param->fork_s);
		sem_post(philo->param->fork_s);
		return ;
	}
	display_state(philo, " has taken a fork\n");
}

static void		eat(t_philo *philo)
{
	sem_wait(philo->eating_death_s);
	if (philo->param->b_dead)
	{
		sem_post(philo->eating_death_s);
		sem_post(philo->param->fork_s);
		sem_post(philo->param->fork_s);
		return ;
	}
	philo->nb_meal++;
	sem_post(philo->eating_death_s);
	display_state(philo, " is eating\n");
	ft_usleep(philo->param->time_to_eat);
	gettimeofday(&philo->time_last_meal, NULL);
	sem_post(philo->param->fork_s);
	sem_post(philo->param->fork_s);
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
