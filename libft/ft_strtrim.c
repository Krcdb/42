/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:22:31 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/17 20:07:05 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(const char *s)
{
	char	*fresh;
	size_t	len;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[j]))
		j--;
	len = j - i;
	if (i == ft_strlen(s))
		return (fresh = ft_strnew(0));
	if (!(fresh = (char*)malloc(sizeof(*fresh) * len + 2)))
		return (NULL);
	while (i <= j)
		*fresh++ = s[i++];
	*fresh = '\0';
	fresh -= len + 1;
	return (fresh);
}
