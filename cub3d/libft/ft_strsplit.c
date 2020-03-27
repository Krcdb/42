/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:28:35 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/17 22:43:15 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	ft_count_len(const char *str, char c)
{
	int count;

	count = 0;
	while (*str && *str != c)
	{
		str++;
		count++;
	}
	return (count);
}

static int	ft_count_word(const char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (!(*str))
			return (count);
		count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

char		**ft_strsplit(const char *str, char c)
{
	char	**tab;
	int		len;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	if (!(tab = (char**)malloc(sizeof(*tab) * ft_count_word(str, c) + 1)))
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			len = ft_count_len(str, c);
			if (!(tab[i] = ft_strsub(str, 0, len)))
				return (NULL);
			str += len;
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}
