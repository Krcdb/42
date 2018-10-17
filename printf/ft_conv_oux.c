/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:44:29 by mmartine          #+#    #+#             */
/*   Updated: 2018/10/17 21:55:38 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*set_z(t_moche *d, char *s)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (d->pre_flag)
		size = d->precision - ft_strlen(s);
	else if (d->zero_flag && d->width)
		size = d->width - ft_strlen(s) - d->hash_flag;
	if (size > 0)
	{
		tmp = ft_strnew(size);
		while (i < size)
			tmp[i++] = '0';
	}
	else
		tmp = ft_strnew(0);
	return (tmp);
}

static char		*set_pre(t_moche *d, char *s)
{
	char	*tmp;

	tmp = ft_strnew(2);
	if ((d->type == 'x' || d->type == 'X') && d->hash_flag)
	{
		tmp[0] = '0';
		tmp[1] = 'x';
		d->hash_flag++;
	}
	else if ((d->type == 'o' || d->type == 'O') && d->hash_flag)
	{
		d->hash_flag++;
		d->precision--;
		tmp[0] = '0';
	}
	if (d->zero_flag || (ft_strlen(s) < d->precision))
		tmp = ft_strjoinfree(tmp, set_z(d, s), 1);
	return (ft_strjoinfree(tmp, s, 1));
}

static char		*set_sp(int size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(size);
	while (i < size)
		tmp[i++] = ' ';
	return (tmp);
}

static char		*set(t_moche *d, char *s)
{
	int		size;
	char	*tmp;

	tmp = set_pre(d, s);
	tmp = ft_set_oux_norm(d, s, tmp);
	if (ft_strlen(tmp) < d->width)
	{
		size = d->width - ft_strlen(tmp);
		if (d->minus_flag)
			tmp = ft_strjoinfree(tmp, set_sp(size), 1);
		else
			tmp = ft_strjoinfree(set_sp(size), tmp, 2);
	}
	if (d->type == 'X')
		tmp = ft_toupper(tmp);
	ft_strdel(&s);
	return (tmp);
}

void			ft_conv_oux(t_moche *d)
{
	int		base;
	char	*tmp;

	base = setbase(d);
	if (d->hh_mod && d->type != 'O' && d->type != 'U')
		tmp = ft_utoa_b((unsigned char)va_arg(d->ap, unsigned int), base);
	else if (d->h_mod && d->type != 'U')
		tmp = ft_utoa_b((unsigned short)va_arg(d->ap, unsigned int), base);
	else if (d->l_mod || d->type == 'O' || d->type == 'U')
		tmp = ft_utoa_b(va_arg(d->ap, unsigned long), base);
	else if (d->ll_mod)
		tmp = ft_utoa_b(va_arg(d->ap, unsigned long long int), base);
	else if (d->j_mod)
		tmp = ft_utoa_b(va_arg(d->ap, uintmax_t), base);
	else if (d->z_mod)
		tmp = ft_utoa_b(va_arg(d->ap, size_t), base);
	else
		tmp = ft_utoa_b(va_arg(d->ap, unsigned int), base);
	tmp = set(d, tmp);
	ft_put_conv(d, tmp);
	ft_bzero(tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
}
