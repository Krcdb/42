/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:34:55 by mmartine          #+#    #+#             */
/*   Updated: 2018/04/25 22:15:07 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conv(t_moche *data)
{
	if (data->type == 's')
		ft_conv_s(data);
	else if (data->type == 'c')
		ft_conv_c(data);
	else if (data->type == 'o' || data->type =='O' || data->type == 'u' || data->type == 'x' || 
			data->type == 'X')
		ft_conv_oux(data);
}
