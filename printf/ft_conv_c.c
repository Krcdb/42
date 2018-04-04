/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:35:01 by mmartine          #+#    #+#             */
/*   Updated: 2018/03/27 00:56:58 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_set_width_minus(t_moche *data, char *tmp, char c)
{
	int		size;

	size = data->width;
	size--;
	if (data->minus_flag)
	{
		*tmp++ = c;
		while (size--)
			*tmp++ = ' ';
	}
	else
	{
		while (size--)
			*tmp++ = ' ';
		*tmp++ = c;
	}
	return (tmp - data->width);
}

void		ft_conv_c(t_moche *data)
{
	char	*tmp;
	char	c;
	
	c = va_arg(data->ap, int);
	if (data->width <= 1)
	{
		data->buff[data->i_buff++] = c;
		data->ret++;
	}
	else
	{
		if (!(tmp = (char*)malloc((sizeof *tmp) * data->width + 1)))
			return;;
		tmp = ft_set_width_minus(data, tmp, c);
		while (*tmp)
		{
			data->buff[data->i_buff++] = *tmp++;
			data->ret++;
		}
	}
}
