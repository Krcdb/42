/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:55:49 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:13:30 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			is_valid_extension(const char *path, const char *ext)
{
	int		l;

	l = ft_strlen(path);
	if (path[l - 4] != ext[0] || path[l - 3] != ext[1] ||
		path[l - 2] != ext[2] || path[l - 1] != ext[3])
		return (0);
	return (1);
}

int			is_filepath_valid(const char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
