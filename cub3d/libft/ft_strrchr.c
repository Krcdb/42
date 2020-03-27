/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:09:11 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 21:00:05 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	while (len != -1)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s--;
		len--;
	}
	if (*s == '\0' && (unsigned char)c == '\0')
		return ((char*)s);
	return (NULL);
}
