/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:31:55 by memartin          #+#    #+#             */
/*   Updated: 2020/04/25 17:58:58 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int			is_shoot_hit(char c)
{
	if (is_wall(c) || c == 'm')
		return (1);
	return (0);
}

static void			dda_shoot(t_data *d)
{
	d->hit = 0;
	while (!d->hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_x;
			d->ray_x += d->step_x;
		}
		else
		{
			d->side_dist_y += d->delta_y;
			d->ray_y += d->step_y;
		}
		if (is_shoot_hit(d->map[d->ray_y][d->ray_x]))
			d->hit = 1;
	}
	if (d->map[d->ray_y][d->ray_x] == 'm')
		d->map[d->ray_y][d->ray_x] = 'k';
		
}

static void			shoot_dectection(t_data *d)
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
	dda_shoot(d);
}

void				player_shoot(t_data *d)
{
	d->b_shoot = 1;
	if (d->inventory == 1 || d->inventory == 2 || d->inventory == 3)
		shoot_dectection(d);
}
