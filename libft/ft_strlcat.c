/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:03:15 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 19:15:11 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			slen;
	size_t			dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = 0;
	if (size <= dlen)
		return (slen + size);
	while (dst[i] && i < size - 1)
		i++;
	while (i < size - 1 && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (slen + dlen);
}
