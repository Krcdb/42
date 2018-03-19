/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:48:20 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/17 20:10:37 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;
	char		*finder;

	len = ft_strlen(s2);
	if (!len)
		return ((char *)s1);
	finder = (char *)s1;
	i = 0;
	while (i < n && *finder)
	{
		if (ft_strncmp(finder, s2, len) == 0)
		{
			if (i + len > n)
				return (NULL);
			return (finder);
		}
		finder++;
		i++;
	}
	return (NULL);
}
