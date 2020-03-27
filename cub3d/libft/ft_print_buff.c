/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:33:22 by mmartine          #+#    #+#             */
/*   Updated: 2018/11/06 19:17:57 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_buff(t_moche *data)
{
	data->buff[data->i_buff] = '\0';
	ft_putstr(data->buff);
	bzero(data->buff, BUFF_SIZE);
	data->i_buff = 0;
}
