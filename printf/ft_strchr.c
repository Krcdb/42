/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:56:49 by mmartine          #+#    #+#             */
/*   Updated: 2018/03/27 01:24:19 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	while (*tmp)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
	}
	if (*tmp == '\0' && (unsigned char)c == '\0')
		return (tmp);
	return (NULL);
}
