/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:17:08 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:21:15 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	after_move_1(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)d->pos_x] == 'n')
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

void		after_move(t_data *d)
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
	else
		after_move_1(d);
}

void		step_sound(t_data *d)
{
	d->diff_time = get_diff_time(d->old_step_time);
	if (d->diff_time >= 0.45)
	{
		d->old_step_time = clock();
		system("aplay ./sound/step.wav &>/dev/null &");
	}
}
