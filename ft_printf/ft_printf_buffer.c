/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:06 by memartin          #+#    #+#             */
/*   Updated: 2020/02/04 18:17:07 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_buffer(t_print *p)
{
	int		i;

	i = 0;
	p->result[p->buff_i] = '\0';
	ft_putstr(p->result);
	p->buff_i = 0;
	p->result[p->buff_i] = '\0';
}
