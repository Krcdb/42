/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:54:35 by memartin          #+#    #+#             */
/*   Updated: 2020/04/26 14:12:48 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				is_wall(char c)
{
	if (c == '1' || c == 'e' || c == 'h' || c == 'd' || c == 'l')
		return (1);
	return (0);
}

int				is_sprite(char c)
{
	if (c == 'm' || c == 'k' || c == 'p' || c == 's' || c == 'n' ||
		c == 'g' || c == 'c')
		return (1);
	return (0);
}

int				is_walk(char c)
{
	if (c == '0' || c == 'h' || c == 'k' || c == 'p' || c == 's' ||
		c == 'n' || c == 'c')
		return (1);
	return (0);
}

static void		action_resolution(t_data *d)
{
	d->b_action = 1;
	if (d->side_dist_x < d->side_dist_y)
		d->ray_x += d->step_x;
	else
		d->ray_y += d->step_y;
	if (d->map[d->ray_y][d->ray_x] == 'd')
	{
		system("aplay ./sound/slidoor.wav $>/dev/null &");
		d->map[d->ray_y][d->ray_x] = '0';
	}
	else if (d->map[d->ray_y][d->ray_x] == 'e')
	{
		system("aplay ./sound/endsong.wav");
		exit_game(d);
	}
	else if (d->map[d->ray_y][d->ray_x] == 'l')
	{
		if (d->inventory == 4 && d->b_handcard)
		{
			d->map[d->ray_y][d->ray_x] = '0';
			d->inventory = 0;
			d->b_handcard = 0;
			system("aplay ./sound/slidoor.wav $>/dev/null &");
		}
	}
}

void			action_detection(t_data *d)
{
	d->delta_x = sqrt(1 + (d->dir_y * d->dir_y) / (d->dir_x * d->dir_x));
	d->delta_y = sqrt(1 + (d->dir_x * d->dir_x) / (d->dir_y * d->dir_y));
	d->ray_x = (int)d->pos_x;
	d->ray_y = (int)d->pos_y;
	if (d->dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->pos_x - d->ray_x) * d->delta_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->ray_x + 1 - d->pos_x) * d->delta_x;
	}
	if (d->dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->pos_y - d->ray_y) * d->delta_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->ray_y + 1 - d->pos_y) * d->delta_y;
	}
	action_resolution(d);
}
