/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:43:17 by mmartine          #+#    #+#             */
/*   Updated: 2018/05/17 23:56:31 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fresh;
	int		len;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (NULL);
		else if (s1 == NULL)
			return (fresh = s2);
		else if (s2 == NULL)
			return (fresh = s1);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(fresh = (char*)malloc(sizeof(*fresh) * (len + 1))))
		return (NULL);
	while (*s1)
		*fresh++ = *s1++;
	while (*s2)
		*fresh++ = *s2++;
	*fresh = '\0';
	fresh -= len;
	return (fresh);
}
