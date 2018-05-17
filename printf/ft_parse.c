/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:31:28 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/18 00:03:20 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flag(t_moche *data, const char *form)
{
	if (form[data->i_form] == '#')
		data->hash_flag = 1;
	else if (form[data->i_form] == '-')
	{
		data->zero_flag = 0;
		data->minus_flag = 1;
	}
	else if (form[data->i_form] == '+')
	{	
		data->sp_flag = 0;
		data->plus_flag = 1;
	}
	else if (form[data->i_form] == '0' && !data->minus_flag)
		data->zero_flag = 1;
	else if (form[data->i_form] == ' ' && !data->plus_flag)
		data->sp_flag = 1;
	else
		return (0);
	data->i_form++;
	return (1);
}

int		ft_check_width(t_moche *data, const char *form)
{
	if (ft_isdigit(form[data->i_form]))
	{
		data->width = ft_atoi(form + data->i_form);
		data->i_form += ft_intsize(data->width);
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
		return (1);
	}
	else if (form[data->i_form] == '.')
	{
		data->i_form++;
		data->pre_flag = 1;
		return (1);
	}
	return (0);
}

int		ft_check_mod(t_moche *data, const char *form)
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
	else if (form[data->i_form] == 'j')
		data->j_mod = 1;
	else if (form[data->i_form] == 'z')
		data->z_mod = 1;
	else
		return (0);
	data->i_form++;
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
			data->type = form[data->i_form];
			data->i_form++;
		}
	}
	ft_conv(data);
}
