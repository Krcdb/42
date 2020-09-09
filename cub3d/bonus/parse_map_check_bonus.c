/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:02:21 by memartin          #+#    #+#             */
/*   Updated: 2020/05/02 12:24:24 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int		is_corner(t_data *d, size_t x, size_t y)
{
	if (x == 0 && y == 0)
		return (1);
	else if (x == 0 && y == d->map_y - 1)
		return (1);
	else if (x == d->map_x - 1 && y == 0)
		return (1);
	else if (x == d->map_x - 1 && y == d->map_y - 1)
		return (1);
	return (0);
}

static int		is_corner_valid(t_data *d, size_t x, size_t y)
{
	if (x == 0 && y == 0 &&
			((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
			(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
		return (0);
	else if (x == (d->map_x - 1) && y == 0 &&
			((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
			(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
		return (0);
	else if (x == 0 && y == (d->map_y - 1) &&
			((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
			(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);
	else if (x == (d->map_x - 1) && y == (d->map_y - 1) &&
			((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
			(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);
	return (1);
}

static int		is_border_valid(t_data *d, size_t x, size_t y)
{
	if (!is_corner_valid(d, x, y))
		return (0);
	if (!is_corner(d, x, y))
	{
		if (x == 0 && ((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
					(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1') ||
					(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
			return (0);
		else if (x == (d->map_x - 1) &&
					((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
					(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1') ||
					(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
			return (0);
		else if (y == 0 &&
					((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
					(d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
					(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
			return (0);
		else if (y == (d->map_y - 1) &&
					((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
					(d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
					(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
			return (0);
	}
	return (1);
}

static int		is_valid_char(t_data *d, t_parse *p, size_t x, size_t y)
{
	if (x == 0 || y == 0 || x == d->map_x - 1 || y == d->map_y - 1)
	{
		if (p->c != ' ' && p->c != '1')
			return (0);
		else if (p->c == ' ' && !is_border_valid(d, x, y))
			return (0);
		return (1);
	}
	else if (p->c == ' ' && ((d->map[y][x + 1] != ' ' &&
				d->map[y][x + 1] != '1') ||
				(d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
				(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1') ||
				(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);
	if ((p->c == 'N' || p->c == 'S' || p->c == 'W' || p->c == 'E') && p->player)
		return (0);
	else if ((p->c == 'N' || p->c == 'S' ||
			p->c == 'W' || p->c == 'E') && !p->player)
		set_player_pos(d, p, x, y);
	return (1);
}

void			is_map_valid(t_data *d, t_parse *p)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < d->map_y)
	{
		x = 0;
		while (x < d->map_x)
		{
			p->c = d->map[y][x];
			if (!is_valid_char(d, p, x, y))
			{
				p->error = 1;
				d->error.e_map = 1;
				return ;
			}
			x++;
		}
		y++;
	}
}
