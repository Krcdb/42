/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:44:29 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/13 02:17:09 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_setbase(t_moche *d)
{
	if (d->type == 'o' || d->type == 'O')
		return (8);
	else if (d->type == 'x' || d->type == 'X')
		return (16);
	return (10);
}

static char		*ft_set_pre(t_moche *d)
{
	char	*pre;

	if (d->type == 'x' || d->type == 'X')
	{
		pre = ft_strnew(2);
		pre[0] = '0';
		pre[1] = 'x';
	}
	else if (d->type == 'o' || d->type == 'O')
	{
		pre = ft_strnew(1);
		pre[0] = '0';
	}
	else
		return (NULL);
	return (pre);
}


static char		*ft_set(t_moche *d, char *s)
{
	int		size;
	char	*tmp;
	char	*pre;

	pre = ft_set_pre(d);
	size = ft_strlen(pre) + ft_strlen(s);
	tmp = ft_strnew(size);
	while (*pre)
		*tmp++ = *pre++;
	while (*s)
		*tmp++ = *s++;
	return (tmp - size);
}


void			ft_conv_oux(t_moche *d)
{
	int		base;
	char	*tmp;

	base = ft_setbase(d);
	if (d->hh_mod)
		tmp = ft_utoa_b((unsigned char)va_arg(d->ap, unsigned int), base);
	else if (d->h_mod)
		tmp = ft_utoa_b((unsigned short)va_arg(d->ap, unsigned int), base);
	else if (d->l_mod || d->type == 'O')
		tmp = ft_utoa_b(va_arg(d->ap, long unsigned int), base);
	else if (d->ll_mod)
		tmp = ft_utoa_b(va_arg(d->ap, long long unsigned int), base);
	else if (d->j_mod)
		tmp = ft_utoa_b(va_arg(d->ap, intmax_t), base);
	else if (d->z_mod)
		tmp = ft_utoa_b(va_arg(d->ap, size_t), base);
	else
		tmp = ft_utoa_b(va_arg(d->ap, unsigned int), base);
	tmp = ft_set(d, tmp);
	ft_put_conv(d, tmp);
}
