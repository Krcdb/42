/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:53:57 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:12:58 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int			event_key_pressed(int key, void *param)
{
	t_data *d;

	d = (t_data *)param;
	if (key == ESC_KEY)
	{
		d->exit_game = 1;
		exit_game(d);
	}
	else if (key == A_KEY)
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
	return (1);
}

int			event_key_released(int key, void *param)
{
	t_data *d;

	d = (t_data *)param;
	if (key == A_KEY)
		d->strafe_left = 0;
	else if (key == D_KEY)
		d->strafe_right = 0;
	else if (key == W_KEY)
		d->move_forward = 0;
	else if (key == S_KEY)
		d->move_backward = 0;
	else if (key == LEFT_KEY)
		d->rotate_left = 0;
	else if (key == RIGHT_KEY)
		d->rotate_right = 0;
	else if (key == D_KEY)
		d->strafe_right = 0;
	else if (key == SHIFT_KEY)
		d->sprint = 0;
	return (1);
}
