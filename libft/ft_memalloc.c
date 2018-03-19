/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:37:33 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/13 18:37:14 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*tmp;
	size_t	len;

	len = size;
	if (!(mem = malloc(sizeof(*mem) * size)))
		return (NULL);
	tmp = mem;
	while (size--)
		*tmp++ = 0;
	tmp -= len;
	return (mem);
}
