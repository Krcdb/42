/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:33:22 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/14 00:40:26 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_buff(t_moche *data)
{
	data->buff[data->i_buff] = '\0';
	ft_putstr(data->buff);
	bzero(data->buff, BUFF_SIZE);
	data->i_buff = 0;
}
