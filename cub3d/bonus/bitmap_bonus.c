/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:36:37 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:12:30 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		data_to_bitmap(t_data *d, int fd)
{
	int		i;

	i = d->screen_x * d->screen_y - 1;
	while (i >= 0)
	{
		write(fd, &d->img_data[i * d->bpp / 8], 4);
		i--;
	}
}

static void		set_header(t_data *d, int fd)
{
	int		info_size;
	int		plane;
	int		rest;

	info_size = 40;
	plane = 1;
	write(fd, &info_size, 4);
	write(fd, &d->screen_x, 4);
	write(fd, &d->screen_y, 4);
	write(fd, &plane, 2);
	write(fd, &d->bpp, 2);
	rest = 0;
	while (rest < 28)
	{
		write(fd, "\0", 1);
		rest++;
	}
}

static void		flip_pxl(t_data *d, int line, int *i, int j)
{
	char	tmp;
	int		b;

	b = 3;
	while (b >= 0)
	{
		tmp = d->img_data[*i + (line * d->s_l)];
		d->img_data[*i + (line * d->s_l)] =
			d->img_data[j - b + (line * d->s_l - 1)];
		d->img_data[j - b + (line * d->s_l - 1)] = tmp;
		*i = *i + 1;
		b--;
	}
}

static void		flip_data(t_data *d)
{
	int		i;
	int		j;
	int		line;

	line = 0;
	while (line < d->screen_y)
	{
		i = 0;
		j = d->s_l;
		while (i < j && i != j)
		{
			flip_pxl(d, line, &i, j);
			j -= 4;
		}
		line++;
	}
}

void			bitmap(t_data *d)
{
	int		fd;
	int		file_size;
	int		first_pxl;

	fd = open("Cub3d.bmp", O_CREAT | O_RDWR);
	file_size = 14 + 40 + 4 + (d->screen_x * d->screen_y) * 4;
	first_pxl = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pxl, 4);
	set_header(d, fd);
	flip_data(d);
	data_to_bitmap(d, fd);
	close(fd);
	exit_game(d);
}
