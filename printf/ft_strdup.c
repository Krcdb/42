/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:22:44 by mmartine          #+#    #+#             */
/*   Updated: 2018/09/29 23:59:30 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		l;
	char	*dest;

	l = 0;
	while (*src)
	{
		l++;
		src++;
	}
	src -= l;
	if (!(dest = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	dest -= l;
	return (dest);
}
