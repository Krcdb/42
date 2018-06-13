/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_majc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:14:52 by mmartine          #+#    #+#             */
/*   Updated: 2018/06/13 19:07:02 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static char	*set_sp(t_moche *d, char *s, int size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(size);
	while (i < size)
		tmp[i++] = ' ';
	if (d->minus_flag)
		s = ft_strjoinfree(s, tmp, 0);
	else
		s = ft_strjoinfree(tmp, s, 0);
	return (s);
}

void		ft_conv_majc(t_moche *d)
{
	char	*tmp;
	int		c;

	c = va_arg(d->ap, int);
	if (c == 0)
		ft_conv_c(d, 1);
	if (c < 0 || c > 0xFFFFF)
	{
		ft_print_buff(d);
		d->err = 1;
	}
	else
	{
		tmp = ft_strnew(5);
		tmp = ft_conv_uni(tmp, c);
		if (ft_strlen(tmp) < d->width)
			tmp = set_sp(d, tmp, d->width - ft_strlen(tmp));
		ft_put_conv(d, tmp);
	}
}
