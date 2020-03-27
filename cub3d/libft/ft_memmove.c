/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:20:41 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 18:28:04 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		tmp[len];
	char		*d;
	const char	*s;

	if (len >= 128 * 1024 * 1024)
		return (NULL);
	d = dst;
	s = src;
	i = 0;
	while (i < len)
	{
		tmp[i] = *s;
		i++;
		s++;
	}
	i = 0;
	while (i < len)
	{
		*d = tmp[i];
		i++;
		d++;
	}
	return (dst);
}
