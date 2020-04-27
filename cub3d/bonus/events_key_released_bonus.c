/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key_released_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:53:57 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:01:18 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	key_inventory_released(t_data *d, int key)
{
	if (key == KEY_1)
		d->b_one = 0;
	else if (key == KEY_2)
		d->b_two = 0;
	else if (key == KEY_3)
		d->b_three = 0;
	else if (key == KEY_4)
		d->b_four = 0;
}

static int	key_released(t_data *d, int key)
{
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
	else
		return (0);
	return (1);
}

int			event_key_released(int key, void *param)
{
	t_data *d;

	d = (t_data *)param;
	if (key_released(d, key))
		return (1);
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		key_inventory_released(d, key);
	else if (key == E_KEY)
		d->b_action = 0;
	else if (key == SPACE_KEY)
		d->b_shoot = 0;
	return (1);
}
