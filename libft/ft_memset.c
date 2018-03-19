/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:14:55 by mmartine          #+#    #+#             */
/*   Updated: 2017/11/27 15:39:35 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*tb;

	tb = b;
	i = 0;
	while (i < len)
		tb[i++] = (unsigned char)c;
	return (b);
}
