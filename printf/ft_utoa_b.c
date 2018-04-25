/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:11:30 by mmartine          #+#    #+#             */
/*   Updated: 2018/04/25 21:48:01 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_utoa_b(unsigned long long n, int base)
{
	size_t	size;
	char	*res;

	size = ft_intsize_b(n, base);
	if (!(res = (char*)malloc((sizeof *res) * size + 1)))
		return (NULL);
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
