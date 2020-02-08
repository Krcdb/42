/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:21:11 by memartin          #+#    #+#             */
/*   Updated: 2020/02/05 16:52:12 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
