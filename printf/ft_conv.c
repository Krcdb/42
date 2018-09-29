/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:34:55 by mmartine          #+#    #+#             */
/*   Updated: 2018/09/28 20:01:35 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conv(t_moche *data)
{
	if (data->type == 'S' || (data->type == 's' && data->l_mod == 1))
		ft_conv_majs(data);
	else if (data->type == 's')
		ft_conv_s(data);
	else if (data->type == 'C' || (data->type == 'c' && data->l_mod == 1))
		ft_conv_majc(data);
	else if (data->type == 'c' || data->type == '%')
		ft_conv_c(data, 0);
	else if (data->type == 'd' || data->type =='D' || data->type == 'i')
		ft_conv_di(data);
	else if (data->type == 'o' || data->type == 'O' || data->type == 'u' || data->type == 'x' || 
			data->type == 'X' || data->type == 'U')
		ft_conv_oux(data);
	else if (data->type == 'p')
		ft_conv_p(data);
}
