/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:15:41 by memartin          #+#    #+#             */
/*   Updated: 2020/12/06 17:13:02 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int					init_param(t_parameters *param, char **av, int ac)
{
	param->b_dead = FALSE;
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
	philo->r_fork_m = NULL;
	philo->l_fork_m = NULL;
	philo->display_m = NULL;
	philo->eating_death_m = NULL;
	philo->param = NULL;
	philo->next = NULL;
}

static t_philo		*new_philo(t_parameters *param, int nb)
{
	t_philo		*new_philo;

	if (!(new_philo = (t_philo*)malloc(sizeof(t_philo))))
		return (NULL);
	set_philo_null(new_philo, nb);
	if (!(new_philo->r_fork_m = malloc(sizeof(pthread_mutex_t)))
		|| !(new_philo->eating_death_m = malloc(sizeof(pthread_mutex_t))))
		return (NULL);
	if (pthread_mutex_init(new_philo->r_fork_m, NULL)
		|| pthread_mutex_init(new_philo->eating_death_m, NULL))
		return (NULL);
	new_philo->param = param;
	return (new_philo);
}

int					init_philo(t_philo_one *data)
{
	size_t		i;
	t_philo		*tmp;

	i = 0;
	tmp = new_philo(data->param, i++);
	if (!tmp || !(tmp->display_m = malloc(sizeof(pthread_mutex_t))))
		return (FAILURE);
	data->philo = tmp;
	while (i < data->param->nb_philo)
	{
		tmp->next = new_philo(data->param, i++);
		if (!tmp->next)
			return (FAILURE);
		tmp->next->l_fork_m = tmp->r_fork_m;
		tmp->next->display_m = tmp->display_m;
		tmp = tmp->next;
	}
	data->philo->l_fork_m = tmp->r_fork_m;
	sort_philo(data->philo);
	return (SUCCES);
}
