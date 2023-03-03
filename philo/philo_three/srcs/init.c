/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:15:41 by memartin          #+#    #+#             */
/*   Updated: 2020/12/07 17:05:55 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int					init_param(t_parameters *param, char **av, int ac)
{
	param->b_dead = FALSE;
	param->pids = NULL;
	if (!atos_verif(&param->nb_philo, av[1])
		|| !atos_verif(&param->time_to_die, av[2])
		|| !atos_verif(&param->time_to_eat, av[3])
		|| !atos_verif(&param->time_to_sleep, av[4]))
		return (FAILURE);
	if (ac == 6)
	{
		if (!atos_verif(&param->nb_meal_needed, av[5]))
			return (FAILURE);
	}
	else
		param->nb_meal_needed = -1;
	if (param->nb_philo < 2)
		return (FAILURE);
	param->time_to_die *= 1000;
	param->time_to_eat *= 1000;
	param->time_to_sleep *= 1000;
	return (SUCCES);
}

static void			sort_philo(t_philo *philo)
{
	t_philo		*tmp;
	t_philo		*odd;
	t_philo		*pair;
	t_philo		*tmp_pair;

	tmp = philo;
	odd = philo;
	pair = philo->next;
	tmp_pair = pair;
	while (tmp)
	{
		if (tmp->nb % 2 && tmp->nb != 1)
		{
			odd->next = tmp;
			odd = odd->next;
		}
		else if (!(tmp->nb % 2) && tmp->nb != 2)
		{
			tmp_pair->next = tmp;
			tmp_pair = tmp_pair->next;
		}
		tmp = tmp->next;
	}
	tmp_pair->next = NULL;
	odd->next = pair;
}

static void			set_philo_null(t_philo *philo, int nb)
{
	philo->nb = nb + 1;
	philo->nb_meal = 0;
	philo->done = FALSE;
	philo->param = NULL;
	philo->next = NULL;
}

static t_philo		*new_philo(t_parameters *param, int nb)
{
	t_philo		*new_philo;

	if (!(new_philo = (t_philo*)malloc(sizeof(t_philo))))
		return (NULL);
	set_philo_null(new_philo, nb);
	sem_unlink("/eating_death_s");
	new_philo->eating_death_s = sem_open("/eating_death_s",
		O_CREAT, S_IRWXU | S_IRWXO, 1);
	if (new_philo->eating_death_s == SEM_FAILED)
	{
		if (new_philo)
			free(new_philo);
		return (NULL);
	}
	new_philo->param = param;
	return (new_philo);
}

int					init_philo(t_philo_three *data)
{
	size_t		i;
	t_philo		*tmp;

	i = 0;
	tmp = new_philo(data->param, i++);
	if (!tmp)
		return (FAILURE);
	data->philo = tmp;
	while (i < data->param->nb_philo)
	{
		tmp->next = new_philo(data->param, i++);
		if (!tmp->next)
			return (FAILURE);
		tmp = tmp->next;
	}
	sort_philo(data->philo);
	return (SUCCES);
}
