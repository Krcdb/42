/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:03:53 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:20:42 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void			strafe_left(t_data *d)
{
	int		old_x;
	int		old_y;

	old_x = (int)d->pos_x;
	old_y = (int)d->pos_y;
	if (is_walk(d->map[(int)d->pos_y][(int)(d->pos_x - d->plane_x * d->speed)]))
		d->pos_x -= d->plane_x * d->speed;
	if (is_walk(d->map[(int)(d->pos_y - d->plane_y * d->speed)][(int)d->pos_x]))
		d->pos_y -= d->plane_y * d->speed;
	if (old_x != (int)d->pos_x || old_y != (int)d->pos_y)
		after_move(d);
	step_sound(d);
}

void			strafe_right(t_data *d)
{
	int		old_x;
	int		old_y;

	old_x = (int)d->pos_x;
	old_y = (int)d->pos_y;
	if (is_walk(d->map[(int)d->pos_y][(int)(d->pos_x + d->plane_x * d->speed)]))
		d->pos_x += d->plane_x * d->speed;
	if (is_walk(d->map[(int)(d->pos_y + d->plane_y * d->speed)][(int)d->pos_x]))
		d->pos_y += d->plane_y * d->speed;
	if (old_x != (int)d->pos_x || old_y != (int)d->pos_y)
		after_move(d);
	step_sound(d);
}

void			move_forward(t_data *d)
{
	int		old_x;
	int		old_y;

	old_x = (int)d->pos_x;
	old_y = (int)d->pos_y;
	if (is_walk(d->map[(int)d->pos_y][(int)(d->pos_x + d->dir_x * d->speed)]))
		d->pos_x += d->dir_x * d->speed;
	if (is_walk(d->map[(int)(d->pos_y + d->dir_y * d->speed)][(int)d->pos_x]))
		d->pos_y += d->dir_y * d->speed;
	if (old_x != (int)d->pos_x || old_y != (int)d->pos_y)
		after_move(d);
	step_sound(d);
}

void			move_backward(t_data *d)
{
	int		old_x;
	int		old_y;

	old_x = (int)d->pos_x;
	old_y = (int)d->pos_y;
	if (is_walk(d->map[(int)d->pos_y][(int)(d->pos_x - d->dir_x * d->speed)]))
		d->pos_x -= d->dir_x * d->speed;
	if (is_walk(d->map[(int)(d->pos_y - d->dir_y * d->speed)][(int)d->pos_x]))
		d->pos_y -= d->dir_y * d->speed;
	if (old_x != (int)d->pos_x || old_y != (int)d->pos_y)
		after_move(d);
	step_sound(d);
}
