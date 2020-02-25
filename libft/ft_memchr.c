/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:31:55 by mmartine          #+#    #+#             */
/*   Updated: 2019/11/13 13:12:51 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*tmp;

	tmp = s;
	while (n && *tmp)
	{
		if (*tmp == (unsigned char)c)
			return ((void*)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
