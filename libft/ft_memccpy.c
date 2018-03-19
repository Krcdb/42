/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:28:04 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/18 01:03:35 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	i = 0;
	while (i < n && s[i] != (unsigned char)c)
		i++;
	if (n == i)
	{
		ft_memcpy(d, s, i);
		return (NULL);
	}
	else
	{
		ft_memcpy(d, s, i + 1);
		return (d + (i + 1));
	}
	return (NULL);
}
