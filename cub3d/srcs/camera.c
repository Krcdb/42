/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:00:22 by memartin          #+#    #+#             */
/*   Updated: 2020/04/30 14:10:57 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_plane_dir(t_data *d, double dir_y, double p_x, double p_y)
{
	d->dir_y = dir_y;
	d->plane_x = p_x;
	d->plane_y = p_y;
}

void			init_pos_camera(t_data *d)
{
	d->pos_x = (double)d->player_x + 0.4999;
	d->pos_y = (double)d->player_y + 0.4999;
	if (d->p_orientation == 'N')
	{
		d->dir_x = 0;
		set_plane_dir(d, -1, 0.66, 0);
	}
	else if (d->p_orientation == 'S')
	{
		d->dir_x = 0;
		set_plane_dir(d, 1, -0.66, 0);
	}
	else if (d->p_orientation == 'W')
	{
		d->dir_x = -1;
		set_plane_dir(d, 0, 0, -0.66);
	}
	else if (d->p_orientation == 'E')
	{
		d->dir_x = 1;
		set_plane_dir(d, 0, 0, 0.66);
	}
}

void			rotate_left(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->dir_x;
	old_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(d->rotation) - d->dir_y * sin(d->rotation);
	d->dir_y = old_dir_x * sin(d->rotation) + d->dir_y * cos(d->rotation);
	d->plane_x = d->plane_x * cos(d->rotation) - d->plane_y * sin(d->rotation);
	d->plane_y = old_plane_x * sin(d->rotation) + d->plane_y * cos(d->rotation);
}

void			rotate_right(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->dir_x;
	old_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(-d->rotation) - d->dir_y * sin(-d->rotation);
	d->dir_y = old_dir_x * sin(-d->rotation) + d->dir_y * cos(-d->rotation);
	d->plane_x = d->plane_x * cos(-d->rotation) -
		d->plane_y * sin(-d->rotation);
	d->plane_y = old_plane_x * sin(-d->rotation) +
		d->plane_y * cos(-d->rotation);
}
