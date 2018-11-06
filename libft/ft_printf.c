/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:33:56 by mmartine          #+#    #+#             */
/*   Updated: 2018/11/06 19:17:28 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *form, ...)
{
	t_moche	data;

	ft_data_init(&data);
	va_start(data.ap, form);
	while (form[data.i_form])
	{
		if (data.i_buff >= BUFF_SIZE - 1)
			ft_print_buff(&data);
		else if (form[data.i_form] != '%')
			ft_putchar_buff(&data, form);
		else if (form[data.i_form] == '%' && form[data.i_form + 1] == '%')
		{
			data.i_form++;
			ft_putchar_buff(&data, form);
		}
		else if (form[data.i_form] == '%')
			ft_parse(&data, form);
		if (data.err)
			return (-1);
		ft_data_reset(&data);
	}
	ft_print_buff(&data);
	va_end(data.ap);
	return (data.ret);
}
