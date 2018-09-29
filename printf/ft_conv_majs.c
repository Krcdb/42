/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_majs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:10:29 by mmartine          #+#    #+#             */
/*   Updated: 2018/09/30 01:48:40 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char	*set(t_moche *d, int *s)
{
	char	*tmp;
	char	*buff;
	int		size;

	d->pre_flag = 0;
	tmp = ft_strnew(0);
	size = 0;
	while (*s)
	{
		buff = ft_strnew(5);
		buff = ft_conv_uni(buff, *s);
		size += ft_strlen(buff);
		tmp = ft_strjoinfree(tmp, buff, 3);
		s++;
	}
	return (tmp);
}


void		ft_conv_majs(t_moche *d)
{
	int		*tmp;
	char	*ret;

	tmp = va_arg(d->ap, int*);
	if (tmp == 0)
		ret = ft_strdup("(null)");
	else
		ret = set(d, tmp);
	ft_put_conv(d, ret);
	ft_strdel(&ret);
}
