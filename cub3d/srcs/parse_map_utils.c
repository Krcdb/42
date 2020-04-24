/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:07:33 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 12:54:50 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				is_valid_map_char(char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != '2' && c != 'N' && c != 'E'
			&& c != 'W' && c != 'S')
		return (0);
	return (1);
}

void			set_player_pos(t_data *d, t_parse *p, int x, int y)
{
	d->map[y][x] = '0';
	p->player = 1;
	d->player_x = x;
	d->player_y = y;
	d->p_orientation = p->c;
}

void			set_parse_map_error(t_data *d, t_parse *p)
{
	if (p->player && !p->error)
		p->m_ok = 1;
	else
	{
		p->error = 1;
		d->error.e_map = 1;
	}
}

int				is_corner_valid(t_data *d, size_t x, size_t y)
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
