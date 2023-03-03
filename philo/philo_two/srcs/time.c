/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:55:44 by memartin          #+#    #+#             */
/*   Updated: 2020/12/07 17:38:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			ft_usleep(size_t n)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(10);
		gettimeofday(&now, NULL);
		if ((size_t)((now.tv_sec - start.tv_sec) * 1000000 +
			(now.tv_usec - start.tv_usec)) >= n)
			break ;
	}
}

size_t			get_time_us(struct timeval start)
{
	size_t			time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - start.tv_sec) * 1000000 +
		(now.tv_usec - start.tv_usec);
	return (time);
}

size_t			get_time_ms(struct timeval start)
{
	return (get_time_us(start) / 1000);
}
