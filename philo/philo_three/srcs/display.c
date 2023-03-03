/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:07:40 by memartin          #+#    #+#             */
/*   Updated: 2020/12/09 12:17:34 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void		fill_nb(char **ptr, size_t nb)
{
	size_t			tmp;
	size_t			pow;

	pow = 10;
	tmp = nb;
	while (tmp /= 10)
		pow *= 10;
	while ((pow /= 10))
		*(*ptr)++ = (nb / pow) % 10 + '0';
}

void			fill_str(char **ptr, char *str)
{
	while (*str)
		*(*ptr)++ = *str++;
}

size_t			get_length(size_t nb)
{
	size_t	ret;

	if (nb < 10)
		return (1);
	ret = 0;
	while (nb /= 10)
		ret++;
	return (ret);
}

int				display_state(t_philo *philo, char *str)
{
	char	*msg;
	char	*ptr;
	size_t	time;
	size_t	size_msg;

	sem_wait(philo->param->display_s);
	time = get_time_ms(philo->param->time_start);
	size_msg = 4 + ft_strlen(str);
	size_msg += get_length(time * 10);
	size_msg += get_length(philo->nb * 10);
	if (!(msg = (char*)malloc(sizeof(char) * size_msg)))
		return (FAILURE);
	ptr = msg;
	fill_nb(&ptr, time);
	fill_str(&ptr, "ms ");
	fill_nb(&ptr, philo->nb);
	fill_str(&ptr, str);
	write(1, msg, size_msg - 1);
	free(msg);
	sem_post(philo->param->display_s);
	return (SUCCES);
}

int				display_error(char *str)
{
	write(1, "error : ", ft_strlen("error : "));
	write(1, str, ft_strlen(str));
	return (SUCCES);
}
