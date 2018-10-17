/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:31:28 by mmartine          #+#    #+#             */
/*   Updated: 2018/10/02 14:33:18 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flag(t_moche *data, const char *form)
{
	if (form[data->i_form] == '#')
		data->hash_flag = 1;
	else if (form[data->i_form] == '-')
		data->minus_flag = 1;
	else if (form[data->i_form] == '+')
		data->plus_flag = 1;
	else if (form[data->i_form] == '0')
		data->zero_flag = 1;
	else if (form[data->i_form] == ' ')
		data->sp_flag = 1;
	else
		return (0);
	data->flag = 1;
	data->i_form++;
	return (1);
}

int		ft_check_width(t_moche *data, const char *form)
{
	if (ft_isdigit(form[data->i_form]))
	{
		data->width = ft_atoi(form + data->i_form);
		data->i_form += ft_intsize(data->width);
		data->flag = 1;
		return (1);
	}
	return (0);
}

int		ft_check_pre(t_moche *data, const char *form)
{
	if (form[data->i_form] == '.' && ft_isdigit(form[data->i_form + 1]))
	{
		data->i_form++;
		data->precision = ft_atoi(form + data->i_form);
		data->i_form += ft_intsize(data->precision);
		data->pre_flag = 1;
		data->flag = 1;
		return (1);
	}
	else if (form[data->i_form] == '.')
	{
		data->i_form++;
		data->pre_flag = 1;
		data->flag = 1;
		return (1);
	}
	return (0);
}

int		ft_check_mod(t_moche *data, const char *form)
{
	if (ft_check_mod_norm(data, form))
		data->flag = 1 - 1;
	else if (form[data->i_form] == 'j')
		data->j_mod = 1;
	else if (form[data->i_form] == 'z')
		data->z_mod = 1;
	else
		return (0);
	data->mod_flag = 1;
	data->i_form++;
	data->flag = 1;
	return (1);
}

void	ft_parse(t_moche *data, const char *form)
{
	data->i_form++;
	while (form[data->i_form] && data->type == '0')
	{
		if (ft_check_flag(data, form))
			continue;
		if (ft_check_width(data, form))
			continue;
		if (ft_check_pre(data, form))
			continue;
		if (ft_check_mod(data, form))
			continue;
		if (ft_strchr("sSpdDioOuUxXcC%", form[data->i_form]))
		{
			ft_set_flag(data);
			data->type = form[data->i_form];
			data->i_form++;
		}
		else
			break ;
	}
	ft_conv(data);
}
