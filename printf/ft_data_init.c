/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:35:29 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/10 02:49:05 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_data_init(t_moche *data)
{
	data->i_buff = 0;
	data->ret = 0;
	data->i_form = 0;
	data->type = '0';
	ft_data_reset(data);
}
