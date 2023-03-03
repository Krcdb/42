/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:09:10 by memartin          #+#    #+#             */
/*   Updated: 2020/12/06 16:51:44 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		free_all_philo(t_philo *philo)
{
	t_philo		*tmp;

	tmp = philo->next;
	while (philo)
	{
		if (philo->r_fork_m)
			free(philo->r_fork_m);
		if (philo->eating_death_m)
			free(philo->eating_death_m);
		free(philo);
		philo = tmp;
		if (philo)
			tmp = tmp->next;
	}
}

int				clear_data(t_philo_one *data)
{
	if (!data)
		return (FAILURE);
	if (data->param)
	{
		free(data->param);
		data->param = NULL;
	}
	if (data->philo)
	{
		if (data->philo->display_m)
			free(data->philo->display_m);
		free_all_philo(data->philo);
	}
	free(data);
	return (SUCCES);
}
