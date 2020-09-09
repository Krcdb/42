/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:07:33 by memartin          #+#    #+#             */
/*   Updated: 2020/04/30 11:11:19 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				is_valid_map_char(char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != 'e' && c != 'h' && c != 'd'
		&& c != 'l' && c != 'N' && c != 'E' && c != 'S' && c != 'W'
		&& c != 'm' && c != 'k' && c != 'p' && c != 's' && c != 'n'
		&& c != 'g' && c != 'c')
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
