/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:41:08 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/17 23:53:51 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tablen(char **tab)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_sort_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		max;

	max = ft_tablen(tab);
	i = 0;
	while (max > 0)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
		i++;
		if (i == max)
		{
			max--;
			i = 1;
		}
	}
	return (tab);
}
