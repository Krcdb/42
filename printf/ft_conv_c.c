/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:35:01 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/18 00:23:31 by mmartine         ###   ########.fr       */
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
		{
			if (data->zero_flag)
				*tmp++ = '0';
			else
				*tmp++ = ' ';
		}
		*tmp++ = c;
	}
	return (tmp - data->width);
}

static void	set_c(t_moche *data, char *tmp)
{
	int		size;

	size = data->width - 1;
	while (size--)
		*tmp++ = ' ';
	tmp -= data->width - 1;
	if (data->minus_flag)
	{
		ft_print_buff(data);
		write(1, "\0", 1);
		ft_put_conv(data, tmp);
	}
	else
	{
		data->ret += data->width;
		ft_putstr(tmp);
		write(1, "\0", 1);
	}
	data->ret++;
}

void		ft_conv_c(t_moche *data)
{
	char	*tmp;
	char	c;
	
	if (data->type == 'c')
		c = va_arg(data->ap, int);
	else
		c = '%';
	if (data->width <= 1 && c != '\0')
	{
		data->buff[data->i_buff++] = c;
		data->ret++;
	}
	else if ((c == '\0' || c == 0) && data->width <= 1)
	{
		ft_print_buff(data);
		write(1, "\0", 1);
		data->ret++;
	}
	else 
	{
		if (!(tmp = (char*)malloc((sizeof *tmp) * data->width + 1)))
			return;
		if (c == '\0' || c == 0)
			set_c(data, tmp);
		else
		{
			tmp = ft_set_width_minus(data, tmp, c);
			ft_put_conv(data, tmp);
		}
	}
}
