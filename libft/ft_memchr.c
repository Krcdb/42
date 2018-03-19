/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:31:55 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/12 15:02:11 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*tmp;

	tmp = s;
	while (n)
	{
		if (*tmp == (unsigned char)c)
			return ((void*)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
