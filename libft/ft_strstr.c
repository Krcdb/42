/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:15:12 by mmartine          #+#    #+#             */
/*   Updated: 2017/12/07 09:23:45 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) > ft_strlen(s1) || !s1)
		return (NULL);
	if (!ft_strlen(s2))
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (j == ft_strlen(s2) - 1)
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
