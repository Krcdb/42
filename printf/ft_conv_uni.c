/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:11:29 by mmartine          #+#    #+#             */
/*   Updated: 2018/10/02 15:07:02 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cut(char *buff, int c)
{
	if (c <= 0x7F)
	{
		buff[0] = c;
		buff[1] = '\0';
	}
	else if (c <= 0x7FF)
	{
		buff[0] = 0xC0 | (c >> 6);
		buff[1] = 0x80 | (c & 0x3F);
		buff[2] = '\0';
	}
	return (buff);
}

char		*ft_conv_uni(char *buff, int c)
{
	if (c <= 0x7F || c <= 0x7FF)
		cut(buff, c);
	else if (c <= 0xFFFF)
	{
		buff[0] = 0xE0 | (c >> 12);
		buff[1] = 0x80 | ((c >> 6) & 0x3F);
		buff[2] = 0x80 | (c & 0x3F);
		buff[3] = '\0';
	}
	else if (c <= 0xFFFFF)
	{
		buff[0] = 0xF0 | (c >> 18);
		buff[1] = 0x80 | ((c >> 12) & 0x3F);
		buff[2] = 0x80 | ((c >> 6) & 0x3F);
		buff[3] = 0x80 | (c & 0x3F);
		buff[4] = '\0';
	}
	return (buff);
}
