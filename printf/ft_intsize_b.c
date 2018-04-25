/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:33:38 by mmartine          #+#    #+#             */
/*   Updated: 2018/04/24 22:00:52 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_intsize_b(intmax_t n, int base)
{
	size_t size;

	size = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= base;
	}
	return (size);
}
