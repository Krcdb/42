/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key_pressed_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:53:57 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:02:51 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		key_manager(t_data *d)
{
	if (d->strafe_left)
		strafe_left(d);
	if (d->strafe_right)
		strafe_right(d);
	if (d->move_forward)
		move_forward(d);
	if (d->move_backward)
		move_backward(d);
	if (d->rotate_left)
		rotate_left(d);
	if (d->rotate_right)
		rotate_right(d);
}

static void	key_inventory_1(t_data *d, int key)
{
	if (key == KEY_4 && !d->b_one && !d->b_two && !d->b_three &&
		!d->b_four)
	{
		d->b_four = 1;
		if (d->b_handcard)
			d->inventory = 4;
	}
}

static void	key_inventory(t_data *d, int key)
{
	if (key == KEY_1 && !d->b_one && !d->b_two && !d->b_three && !d->b_four)
	{
		d->b_one = 1;
		if (d->b_pistol)
			d->inventory = 1;
	}
	else if (key == KEY_2 && !d->b_one && !d->b_two && !d->b_three &&
		!d->b_four)
	{
		d->b_two = 1;
		if (d->b_shootgun)
			d->inventory = 2;
	}
	else if (key == KEY_3 && !d->b_one && !d->b_two && !d->b_three &&
		!d->b_four)
	{
		d->b_three = 1;
		if (d->b_nukegun)
			d->inventory = 3;
	}
	else
		key_inventory_1(d, key);
}

static int	key_pressed(int key, t_data *d)
{
	if (key == A_KEY)
		d->strafe_left = 1;
	else if (key == D_KEY)
		d->strafe_right = 1;
	else if (key == W_KEY)
		d->move_forward = 1;
	else if (key == S_KEY)
		d->move_backward = 1;
	else if (key == LEFT_KEY)
		d->rotate_left = 1;
	else if (key == RIGHT_KEY)
		d->rotate_right = 1;
	else if (key == D_KEY)
		d->strafe_right = 1;
	else if (key == SHIFT_KEY)
		d->sprint = 1;
	else
		return (0);
	return (1);
}

int			event_key_pressed(int key, void *param)
{
	t_data *d;

	d = (t_data *)param;
	if (key == ESC_KEY)
	{
		d->exit_game = 1;
		exit_game(d);
	}
	else if (key_pressed(key, d))
		return (1);
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		key_inventory(d, key);
	else if (key == E_KEY && !d->b_action)
		action_detection(d);
	else if (key == SPACE_KEY && !d->b_shoot)
		player_shoot(d);
	return (1);
}
