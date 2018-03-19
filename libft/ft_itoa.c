/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:12:46 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 18:54:20 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static char	*ft_putres(char *res, int len, int n, int neg)
{
	while (len)
	{
		res[--len] += ((n % 10) + '0');
		n /= 10;
	}
	if (neg == 1)
		res[0] = '-';
	return (res);
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		len;
	int		neg;
	char	*res;

	len = 2;
	tmp = n;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg++;
		n = -n;
	}
	while ((tmp = tmp / 10))
		len++;
	len += neg;
	if (!(res = ft_memalloc(len)))
		return (NULL);
	res[--len] = '\0';
	return (ft_putres(res, len, n, neg));
}
