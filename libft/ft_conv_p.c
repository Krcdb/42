/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:35:38 by mmartine          #+#    #+#             */
/*   Updated: 2018/11/06 19:14:40 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_sp(int size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(size);
	while (i < size)
		tmp[i++] = ' ';
	return (tmp);
}

static char	*set(t_moche *d, char *s)
{
	char	*tmp;
	int		size;

	size = 0;
	tmp = ft_strjoinfree("0x", s, 2);
	if (ft_strlen(tmp) < d->width)
	{
		size = d->width - ft_strlen(tmp);
		if (d->minus_flag)
			tmp = ft_strjoinfree(tmp, set_sp(size), 0);
		else
			tmp = ft_strjoinfree(set_sp(size), tmp, 0);
	}
	return (tmp);
}

void		ft_conv_p(t_moche *d)
{
	char	*tmp;

	tmp = ft_utoa_b(va_arg(d->ap, unsigned long int), 16);
	tmp = set(d, tmp);
	ft_put_conv(d, tmp);
	bzero(tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
}
