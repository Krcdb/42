/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:43:54 by memartin          #+#    #+#             */
/*   Updated: 2020/02/07 18:02:09 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_setnull(t_print *p, char *s)
{
	if (s && s[0] == '0' && p->precision == -1)
		if (p->conv == 'd' || p->conv == 'i' || p->conv == 'D' ||
				p->conv == 'x' || p->conv == 'X')
		{
			ft_strdel(&s);
			return (ft_strdup(""));
		}
	return (s);
}

static char		*ft_setprecision(t_print *p, char *s)
{
	char	*ret;

	if (p->conv != 'c' && p->conv != 'C' && p->conv != 's' && p->conv != 'S'
			&& p->precision > (int)ft_strlen(s))
	{
		ret = ft_strnew(p->precision - ft_strlen(s));
		if (ret)
		{
			ft_memset(ret, '0', p->precision - ft_strlen(s));
			return (ret);
		}
	}
	return (ft_strdup(""));
}

static char		*ft_setwidth(t_print *p, char *s, char *precision)
{
	char	*ret;
	int		len;

	len = p->width - ft_strlen(precision) - ft_strlen(s);
	if (len > 0)
	{
		ret = ft_strnew(len);
		if (ret)
		{
			if (!p->precision && p->f_zero)
				ft_memset(ret, '0', len);
			else
				ft_memset(ret, ' ', len);
			return (ret);
		}
	}
	return (ft_strdup(""));
}

void			ft_printf_flags(t_print *p, char *s, char *prefix)
{
	char	*precision;
	char	*width;
	char	*ret;

	s = ft_setnull(p, s);
	precision = ft_setprecision(p, s);
	width = ft_setwidth(p, s, precision);
	ret = ft_joinfree(precision, s);
	if (width && width[0] == '0')
	{
		write(1, "1\n", 2);
		ret = ft_joinfree(width, ret);
		write(1, "2\n", 2);
		ret = ft_joinfree(prefix, ret);
		write(1, "3\n", 2);
	}
	else
	{
		write(1, "4\n", 2);
		ret = ft_joinfree(prefix, ret);
		write(1, "5\n", 2);
		if (p->f_moins)
		{
			write(1, "6\n", 2);
			ret = ft_joinfree(ret, width);
			write(1, "7\n", 2);
		}
		else
		{
			write(1, "8\n", 2);
			ret = ft_joinfree(width, ret);
			write(1, "9\n", 2);
		}
	}
	p->size += ft_strlen(ret);
	ft_printf_add_conv(p, ret);
}
