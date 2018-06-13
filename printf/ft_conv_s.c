/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:35:09 by mmartine          #+#    #+#             */
/*   Updated: 2018/06/13 20:34:04 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_set(t_moche *data, char *tmp, char *s, int just)
{
	while (just--)
	{
		if (data->zero_flag)
			*tmp++ = '0';
		else
			*tmp++ = ' ';
	}
	if (data->precision && data->precision < ft_strlen(s))
	{
		while (data->precision--)
			*tmp++ = *s++;
	}
	else
	{
		while (*s)
			*tmp++ = *s++;
	}
	*tmp = '\0';
	return (tmp);
}

static char	*ft_set_minus(t_moche *data, char *tmp, char *s, int just)
{
	if (data->precision < ft_strlen(s) && data->pre_flag)
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
	*tmp = '\0';
	return (tmp);
}

static char	*ft_set_width_pre(t_moche *d, char *s)
{
	char	*tmp;
	int		size;
	int		just;

	size = 0;
	just = 0;
	if (d->width < ft_strlen(s) && d->precision < ft_strlen(s) && d->width > d->precision)
		size = d->width;
	else if (d->width >= ft_strlen(s) && (d->width > d->precision || d->precision > ft_strlen(s)))
		size = d->width;
	else if ((!d->width && d->pre_flag && d->precision > ft_strlen(s)) || 
			(d->width < d->precision && d->width < ft_strlen(s) && d->precision > ft_strlen(s)))
		size = ft_strlen(s);
	else if (d->pre_flag)
		size = d->precision;
	else
		size = ft_strlen(s);
	if (!(tmp = (char*)malloc((sizeof *tmp) * size + 1)))
		return (NULL);
	if (d->width >= ft_strlen(s) && d->pre_flag && d->precision < ft_strlen(s))
		just = d->width - d->precision;
	else if (d->width < ft_strlen(s) && d->precision < ft_strlen(s) && d->width > d->precision)
		just = d->width - d->precision;
	else if (d->width > ft_strlen(s))
		just = d->width - ft_strlen(s);
	if (d->minus_flag)
		tmp = ft_set_minus(d, tmp, s, just);
	else
		tmp = ft_set(d, tmp, s, just);
	tmp[size] = '\0';
	return (tmp - size);
}

void		ft_conv_s(t_moche *data)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = va_arg(data->ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if ((data->pre_flag && data->precision == 0) || (*tmp == '\0' && data->width))
	{
		if (!(tmp = (char*)malloc((sizeof *tmp) * data->width + 1)))
			return;
		while (i < data->width)
			tmp[i++] = ' ';
	}
	else
		tmp = ft_set_width_pre(data, tmp);
	ft_put_conv(data, tmp);
}
