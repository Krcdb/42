/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:05:56 by memartin          #+#    #+#             */
/*   Updated: 2020/12/07 10:50:33 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		supervisor_verif(t_philo *tmp, size_t *nb)
{
	ft_usleep(100);
	pthread_mutex_lock(tmp->eating_death_m);
	if (tmp->nb_meal == tmp->param->nb_meal_needed)
	{
		*nb += 1;
		tmp->done = TRUE;
	}
	else
	{
		if (get_time_us(tmp->time_last_meal) > tmp->param->time_to_die)
		{
			display_state(tmp, " died\n");
			tmp->param->b_dead = TRUE;
			pthread_mutex_unlock(tmp->eating_death_m);
			return (FAILURE);
		}
	}
	pthread_mutex_unlock(tmp->eating_death_m);
	return (SUCCES);
}

void			supervisor(t_philo_one *data)
{
	t_philo		*tmp;
	size_t		nb;

	nb = 0;
	tmp = data->philo;
	while (nb != data->param->nb_philo)
	{
		if (!tmp->done)
		{
			if (!supervisor_verif(tmp, &nb))
				return ;
		}
		tmp = tmp->next;
		if (!tmp)
			tmp = data->philo;
	}
}
