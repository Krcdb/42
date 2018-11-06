/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:35:09 by mmartine          #+#    #+#             */
/*   Updated: 2018/11/06 19:11:53 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	just = 0;
	size = ft_set_width_pre_s_norm(d, s);
	if (!(tmp = (char*)malloc((sizeof(*tmp) * size + 1))))
		return (NULL);
	if (d->width >= ft_strlen(s) && d->pre_flag &&
			d->precision < ft_strlen(s))
		just = d->width - d->precision;
	else if (d->width < ft_strlen(s) &&
			d->precision < ft_strlen(s) && d->width > d->precision)
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

void		ft_conv_s(t_moche *d)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = va_arg(d->ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (d->width && ft_strlen(tmp) > d->width && !d->pre_flag && tmp != NULL)
	{
		ft_put_conv(d, tmp);
		return ;
	}
	if ((d->pre_flag && d->precision == 0) ||
			(*tmp == '\0' && d->width))
	{
		if (!(tmp = (char*)malloc((sizeof(*tmp) * d->width + 1))))
			return ;
		while (i < d->width)
			tmp[i++] = ' ';
	}
	else
		tmp = ft_set_width_pre(d, tmp);
	ft_put_conv(d, tmp);
	ft_bzero(tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
}
