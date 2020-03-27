/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:31:31 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 19:22:10 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*fresh;
	char	*p;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(fresh = (char*)malloc(sizeof(*fresh) * len + 1)))
		return (NULL);
	p = fresh;
	while (len--)
		*p++ = f(*s++);
	*p = '\0';
	return (fresh);
}
