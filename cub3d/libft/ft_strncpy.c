/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:45:38 by mmartine          #+#    #+#             */
/*   Updated: 2019/10/08 14:27:12 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*d;

	d = dst;
	while (*src && len)
	{
		*d++ = *src++;
		len--;
	}
	while (len)
	{
		*d++ = '\0';
		len--;
	}
	return (dst);
}
