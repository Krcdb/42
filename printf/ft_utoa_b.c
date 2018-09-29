/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:11:30 by mmartine          #+#    #+#             */
/*   Updated: 2018/09/29 23:58:13 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_utoa_b(uintmax_t n, int base)
{
	size_t	size;
	char	*res;

	size = ft_intsize_b(n, base);
	if (!(res = (char*)malloc(sizeof (*res) * size + 1)))
		return (NULL);
	if (n == 0)
	{
		*res = '0';
		return(res);
	}
	res[size] = '\0';
	while (n > 0)
	{
		if ((n % base) > 9)
			res[--size] = (n % base) + 'W';
		else
			res[--size] = (n % base) + '0';
		n /= base;
	}
	return (res);
}
