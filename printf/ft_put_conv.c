/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:14:09 by mmartine          #+#    #+#             */
/*   Updated: 2018/06/13 19:10:35 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_conv(t_moche *d, char *s)
{
	while (*s)
	{
		if (d->i_buff >= BUFF_SIZE)
			ft_print_buff(d);
		d->buff[d->i_buff++] = *s++;
		d->ret++;
	}
	d->buff[d->i_buff] = '\0';
}
