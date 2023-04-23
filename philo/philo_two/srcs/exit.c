/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:09:10 by memartin          #+#    #+#             */
/*   Updated: 2020/12/07 15:14:56 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void		free_all_philo(t_philo *philo)
{
	t_philo		*tmp;

	tmp = philo->next;
	while (philo)
	{
		free(philo);
		philo = tmp;
		if (philo)
			tmp = tmp->next;
	}
}

int				clear_data(t_philo_two *data)
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
		free_all_philo(data->philo);
	}
	free(data);
	return (SUCCES);
}