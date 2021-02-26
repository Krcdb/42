/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:42:35 by mmartine          #+#    #+#             */
/*   Updated: 2020/02/04 16:03:29 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t		ft_strclen(char *str, char c)
{
	size_t		len;

	len = 0;
	if (!str)
		return (0);
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	str -= len;
	return (len);
}

static char			*ft_strjoinfree(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	static char	*rest;
	char		*tmp;
	char		*buff;
	int			rd;

	if (fd < 0 || fd > 1024 || !line)
		return (-1);
	if (rest && *rest)
		tmp = ft_strdup(rest);
	else
		tmp = ft_strnew(1);
	rd = 1;
	while (!(ft_strchr(tmp, '\n')) && rd > 0)
	{
		buff = ft_strnew(BUFF_SIZE + 1);
		rd = read(fd, buff, BUFF_SIZE);
		buff[rd] = '\0';
		tmp = ft_strjoinfree(tmp, buff);
	}
	*line = ft_strsub(tmp, 0, ft_strclen(tmp, '\n'));
	rest = ft_strsub(tmp, ft_strclen(tmp, '\n') + 1, ft_strlen(tmp));
	if (tmp)
		ft_strdel(&tmp);
	return ((*line) ? 1 : rd);
}
