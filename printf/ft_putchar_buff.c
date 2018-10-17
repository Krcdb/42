/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 01:01:03 by mmartine          #+#    #+#             */
/*   Updated: 2018/10/17 18:50:31 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_buff(t_moche *data, const char *form)
{
	if (data->i_buff >= BUFF_SIZE)
	{
		ft_print_buff(data);
		ft_bzero(data->buff, BUFF_SIZE);
		data->i_buff = 0;
	}
	data->buff[data->i_buff] = form[data->i_form];
	data->i_buff++;
	data->i_form++;
	data->ret++;
}
