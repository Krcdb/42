/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:35:56 by mmartine          #+#    #+#             */
/*   Updated: 2018/11/06 19:16:27 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_imtoa(intmax_t n)
{
	size_t	size;
	char	*res;
	int		neg;

	size = ft_intsize(n);
	neg = 0;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	if (!(res = (char*)malloc((sizeof(*res) * size + 1))))
		return (NULL);
	res[size] = '\0';
	while (size)
	{
		res[--size] = (n % 10) + 48;
		n /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
