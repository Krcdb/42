/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:34:24 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:14:27 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char		*cpy_lst_to_map(char *dst, const char *src)
{
	char *d;

	d = dst;
	while (*src != '\0')
		*d++ = *src++;
	return (dst);
}

int			is_map_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2' || c == '3' ||
		c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int			is_map_line(char *line)
{
	while (*line)
	{
		if (!is_map_char(*line))
			return (0);
		line++;
	}
	return (1);
}

int			is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
			return (0);
		line++;
	}
	return (1);
}
