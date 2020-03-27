/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:11:40 by mmartine          #+#    #+#             */
/*   Updated: 2017/12/07 14:05:52 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		len;

	len = size;
	if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
		return (NULL);
	while (len--)
		*str++ = '\0';
	*str = '\0';
	str -= size;
	return (str);
}
