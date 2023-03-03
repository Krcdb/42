/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:08:20 by memartin          #+#    #+#             */
/*   Updated: 2020/12/07 15:15:38 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

size_t			ft_strlen(const char *str)
{
	size_t		ret;

	ret = 0;
	while (*str++)
		ret++;
	return (ret);
}

int				atos_verif(size_t *nb, char *str)
{
	*nb = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		*nb = *nb * 10 + (*str - '0');
		str++;
	}
	return (*str == '\0');
}
