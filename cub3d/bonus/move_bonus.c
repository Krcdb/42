/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:03:53 by memartin          #+#    #+#             */
/*   Updated: 2020/04/26 14:24:20 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		after_move(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)d->pos_x] == 'p')
	{
		d->inventory = 1;
		d->b_pistol = 1;
		d->map[(int)d->pos_y][(int)d->pos_x] = '0';
		system("aplay ./sound/pistolpickup.wav &>/dev/null &");
	}
	else if (d->map[(int)d->pos_y][(int)d->pos_x] == 's')
	{
		d->inventory = 2;
		d->b_shootgun = 1;
		d->map[(int)d->pos_y][(int)d->pos_x] = '0';
		system("aplay ./sound/shootgunpickup.wav &>/dev/null &");
	}
	else if (d->map[(int)d->pos_y][(int)d->pos_x] == 'n')
	{
		d->inventory = 3;
		d->b_nukegun = 1;
		d->map[(int)d->pos_y][(int)d->pos_x] = '0';
		system("aplay ./sound/item.wav &>/dev/null &");
	}
	else if (d->map[(int)d->pos_y][(int)d->pos_x] == 'c')
	{
		d->inventory = 4;
		d->b_handcard = 1;
		d->map[(int)d->pos_y][(int)d->pos_x] = '0';
		system("aplay ./sound/item.wav &>/dev/null &");
	}
}

static void		step_sound(t_data *d)
{
	d->diff_time = get_diff_time(d->old_step_time);
	if (d->diff_time >= 0.45)
	{
		d->old_step_time = clock();
		system("aplay ./sound/step.wav &>/dev/null &");
	}
}

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
