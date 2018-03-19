/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:07:44 by mmartine          #+#    #+#             */
/*   Updated: 2018/02/28 02:38:53 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s && start < ft_strlen(s))
	{
		i = 0;
		if (!(res = ft_strnew(len)))
			return (NULL);
		while (i < len && s[i])
		{
			res[i] = (char)s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
