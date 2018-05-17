/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 00:42:58 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/17 23:00:53 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *set_z(t_moche *d, char *s, int neg)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (d->pre_flag)
		size = d->precision - ft_strlen(s);
	else if (d->zero_flag && d->width)
		size = d->width - ft_strlen(s) - d->sp_flag - d->plus_flag - neg;
	tmp = ft_strnew(size);
	while (i < size)
		tmp[i++] = '0';
	return (tmp);
}

static char	*set_pre(t_moche *d, char *s)
{
	char	*tmp;
	int		neg;

	neg = 0;
	tmp = ft_strnew(1);
	if (d->plus_flag || d->sp_flag || s[0] == '-')
	{
		if (s[0] == '-')
		{
			tmp[0] = '-';
			s++;
			neg++;
			d->plus_flag = 0;
		}
		else if (d->plus_flag)
			tmp[0] = '+';
		else if (d->sp_flag)
			tmp[0] = ' ';
	}
	if (d->zero_flag || (ft_strlen(s) < d->precision))
		tmp = ft_strjoin(tmp, set_z(d, s, neg));
	return (ft_strjoin(tmp, s));
}

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
	tmp = set_pre(d, s);
	if (tmp[0] == '0' && ft_strlen(tmp) == 1 && d->pre_flag)
		tmp[0] = '\0';
	else if ((tmp[0] == ' ' || tmp[0] == '+') && tmp[1] == '0' 
			&& ft_strlen(tmp) == 2 && d->pre_flag)
		tmp[1] = '\0';
	if (ft_strlen(tmp) < d->width)
	{
		size = d->width - ft_strlen(tmp);
		if (d->minus_flag)
			tmp = ft_strjoin(tmp, set_sp(size));
		else
			tmp = ft_strjoin(set_sp(size), tmp);
	}
	return (tmp);
}
			 
void		ft_conv_di(t_moche *d)
{
	char *tmp;

	if (d->h_mod)
		tmp = ft_imtoa((short)va_arg(d->ap, int));
	else if (d->hh_mod)
		tmp = ft_imtoa((char)va_arg(d->ap, int));
	else if (d->ll_mod || d->type == 'D')
		tmp = ft_imtoa(va_arg(d->ap, long long int));
	else if (d->l_mod)
		tmp = ft_imtoa(va_arg(d->ap, long int));
	else if (d->j_mod)
		tmp = ft_imtoa(va_arg(d->ap, size_t));
	else if (d->z_mod)
		tmp = ft_imtoa(va_arg(d->ap, intmax_t));
	else
		tmp = ft_imtoa(va_arg(d->ap, int));
	tmp = set(d, tmp);
	ft_put_conv(d, tmp);
}
