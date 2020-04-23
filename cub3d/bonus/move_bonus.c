/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:03:53 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 00:00:19 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		strafe_left(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x - d->plane_x * d->speed)] == '0' ||
		d->map[(int)d->pos_y][(int)(d->pos_x - d->plane_x * d->speed)] == '3')
		d->pos_x -= d->plane_x * d->speed;
	if (d->map[(int)(d->pos_y - d->plane_y * d->speed)][(int)d->pos_x] == '0' ||
		d->map[(int)(d->pos_y - d->plane_y * d->speed)][(int)d->pos_x] == '3')
		d->pos_y -= d->plane_y * d->speed;
}

void		strafe_right(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x + d->plane_x * d->speed)] == '0' ||
		d->map[(int)d->pos_y][(int)(d->pos_x + d->plane_x * d->speed)] == '3')
		d->pos_x += d->plane_x * d->speed;
	if (d->map[(int)(d->pos_y + d->plane_y * d->speed)][(int)d->pos_x] == '0' ||
		d->map[(int)(d->pos_y + d->plane_y * d->speed)][(int)d->pos_x] == '3')
		d->pos_y += d->plane_y * d->speed;
}

void		move_forward(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x + d->dir_x * d->speed)] == '0' ||
		d->map[(int)d->pos_y][(int)(d->pos_x + d->dir_x * d->speed)] == '3')
		d->pos_x += d->dir_x * d->speed;
	if (d->map[(int)(d->pos_y + d->dir_y * d->speed)][(int)d->pos_x] == '0' ||
		d->map[(int)(d->pos_y + d->dir_y * d->speed)][(int)d->pos_x] == '3')
		d->pos_y += d->dir_y * d->speed;
}

void		move_backward(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x - d->dir_x * d->speed)] == '0' ||
		d->map[(int)d->pos_y][(int)(d->pos_x - d->dir_x * d->speed)] == '3')
		d->pos_x -= d->dir_x * d->speed;
	if (d->map[(int)(d->pos_y - d->dir_y * d->speed)][(int)d->pos_x] == '0' ||
		d->map[(int)(d->pos_y - d->dir_y * d->speed)][(int)d->pos_x] == '3')
		d->pos_y -= d->dir_y * d->speed;
}
