/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:03:53 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 19:33:48 by memartin         ###   ########.fr       */
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
	}
	else if (d->map[(int)d->pos_y][(int)d->pos_x] == 's')
	{
		d->inventory = 2;
		d->b_shootgun = 1;
		d->map[(int)d->pos_y][(int)d->pos_x] = '0';
	}
	else if (d->map[(int)d->pos_y][(int)d->pos_x] == 'n')
	{
		d->inventory = 3;
		d->b_nukegun = 1;
		d->map[(int)d->pos_y][(int)d->pos_x] = '0';
	}
	else if (d->map[(int)d->pos_y][(int)d->pos_x] == 'c')
	{
		d->inventory = 4;
		d->b_handcard = 1;
		d->map[(int)d->pos_y][(int)d->pos_x] = '0';
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
}
