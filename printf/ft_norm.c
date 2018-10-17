/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:12:23 by mmartine          #+#    #+#             */
/*   Updated: 2018/10/17 22:50:24 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			setbase(t_moche *d)
{
	if (d->type == 'o' || d->type == 'O')
		return (8);
	else if (d->type == 'x' || d->type == 'X')
		return (16);
	return (10);
}

int			ft_set_width_pre_s_norm(t_moche *d, char *s)
{
	int		size;

	size = 0;
	if (d->width < ft_strlen(s) && d->precision < ft_strlen(s) &&
			d->width > d->precision && d->pre_flag)
		size = d->width;
	else if (d->width >= ft_strlen(s) && (d->width > d->precision ||
				d->precision > ft_strlen(s)))
		size = d->width;
	else if ((!d->width && d->pre_flag && d->precision > ft_strlen(s)) ||
			(d->width < d->precision && d->width < ft_strlen(s) &&
				d->precision > ft_strlen(s)))
		size = ft_strlen(s);
	else if (d->pre_flag)
		size = d->precision;
	else
		size = ft_strlen(s);
	return (size);
}

char		*ft_set_oux_norm(t_moche *d, char *s, char *tmp)
{
	if (tmp[0] == '0' && ((ft_strlen(tmp) == 1 && d->pre_flag) ||
				(d->precision == 0 && d->pre_flag)) && (d->type == 'u' || d->type == 'U'))
		tmp[0] = '\0';
	else if (tmp[0] == '0' && ((ft_strlen(tmp) == 1 && d->pre_flag) || 
				(d->precision == 0 && d->pre_flag)) && ft_strlen(tmp) <= 1)
		tmp[0] = '\0';
	else if (s[0] == '0' && d->precision == 0 && d->pre_flag &&
			(d->type == 'x' || d->type == 'X'))
		tmp[0] = '\0';
	else if (tmp[0] == '0' && tmp[1] == '0' && ft_strlen(tmp) == 2 &&
			d->hash_flag && d->precision != 1)
		tmp[1] = '\0';
	else if (tmp[0] == '0' && tmp[1] == 'x' && s[0] == '0' && !d->width)
		tmp[1] = '\0';
	else if (tmp[0] == '0' && tmp[1] == 'x' && s[0] == '0' && d->width)
		tmp[1] = '0';
	return (tmp);
}

int			ft_check_mod_norm(t_moche *data, const char *form)
{
	if (form[data->i_form] == 'h')
	{
		if (form[data->i_form + 1] == 'h')
		{
			data->hh_mod = 1;
			data->i_form++;
		}
		else
			data->h_mod = 1;
	}
	else if (form[data->i_form] == 'l')
	{
		if (form[data->i_form + 1] == 'l')
		{
			data->ll_mod = 1;
			data->i_form++;
		}
		else
			data->l_mod = 1;
	}
	else
		return (0);
	return (1);
}

int			ft_conv_c_norm(t_moche *data, char c)
{
	if (data->width <= 1 && c != '\0')
	{
		data->buff[data->i_buff++] = c;
		data->ret++;
	}
	else if ((c == '\0' || c == 0) && data->width <= 1)
	{
		ft_print_buff(data);
		write(1, "\0", 1);
		data->ret++;
	}
	else
		return (0);
	return (1);
}
