/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:00:22 by memartin          #+#    #+#             */
/*   Updated: 2020/04/23 19:04:23 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_pos_camera(t_data *d)
{
	d->plane_x = 0;
	d->plane_y = 0.66;
	d->dir_x = -1;
	d->dir_y = 0;
	d->pos_x = (double)d->player_x + 0.4999;
	d->pos_y = (double)d->player_y + 0.4999;
}

void		rotate_left(t_data *d)
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

void		rotate_right(t_data *d)
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
