/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:44:01 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 19:22:49 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	i = -1;
	len = ft_strlen(s);
	if (!(fresh = (char*)malloc(sizeof(*fresh) * len + 1)))
		return (NULL);
	while (++i < len)
		fresh[i] = f(i, s[i]);
	fresh[i] = '\0';
	return (fresh);
}
