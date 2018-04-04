/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:35:09 by mmartine          #+#    #+#             */
/*   Updated: 2018/03/27 22:29:32 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_set(t_moche *data, char *tmp, char *s, int just)
{
	while (just--)
		*tmp++ = ' ';
	if (data->precision)
	{
		while (data->precision--)
			*tmp++ = *s++;
	}
	else
	{
		while (*s)
			*tmp++ = *s++;
	}
	return (tmp);
}

static char	*ft_set_minus(t_moche *data, char *tmp, char *s, int just)
{
	if (data->precision)
	{
		while (data->precision--)
			*tmp++ = *s++;
	}
	else
	{
		while (*s)
			*tmp++ = *s++;
	}
	while (just--)
		*tmp++ = ' ';
	return (tmp);
}


static char	*ft_set_width_pre(t_moche *data, char *s)
{
	char	*tmp;
	int		size;
	int		just;

	size = 0;
	just = 0;
	if (data->width > ft_strlen(s) && data->width > data->precision)
		size = data->width;
	else if (data->precision && data->precision < ft_strlen(s))
		size = data->precision;
	else
		size = ft_strlen(s);
	if (!(tmp = (char*)malloc((sizeof *tmp) * size + 1)))
		return (NULL);
	if (data->width > ft_strlen(s) && data->precision)
		just = data->width - data->precision;
	else if (data->width > ft_strlen(s))
		just = data->width - ft_strlen(s);
	if (data->minus_flag)
		tmp = ft_set_minus(data, tmp, s, just);
	else
		tmp = ft_set(data, tmp, s, just);
	return (tmp - size);
}

void		ft_conv_s(t_moche *data)
{
	char	*tmp;

	tmp = va_arg(data->ap, char *);
	tmp = ft_set_width_pre(data, tmp);
	while (*tmp)
	{
		data->buff[data->i_buff++] = *tmp++;
		data->ret++;
	}
}
