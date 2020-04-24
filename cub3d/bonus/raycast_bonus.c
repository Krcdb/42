/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:35:39 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 19:01:40 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		set_data(t_data *d, int x)
{
	d->camera_x = (2 * x / (double)(d->screen_x)) - 1;
	d->ray_dir_x = d->dir_x + d->plane_x * d->camera_x;
	d->ray_dir_y = d->dir_y + d->plane_y * d->camera_x;
	d->delta_x = sqrt(1 + (d->ray_dir_y * d->ray_dir_y) /
		(d->ray_dir_x * d->ray_dir_x));
	d->delta_y = sqrt(1 + (d->ray_dir_x * d->ray_dir_x) /
		(d->ray_dir_y * d->ray_dir_y));
	d->side_dist_x = 0;
	d->side_dist_y = 0;
	d->wall_dist = 0;
	d->ray_x = (int)d->pos_x;
	d->ray_y = (int)d->pos_y;
	d->step_x = 0;
	d->step_y = 0;
	d->hit = 0;
	d->side = 0;
	d->text_x = 0;
	d->text_y = 0;
	d->s_text_x = 0;
	d->s_text_y = 0;
	d->text_pos = 0;
	d->wall_x = 0;
	d->step = 0;
}

static void		set_side_dist(t_data *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->pos_x - d->ray_x) * d->delta_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->ray_x + 1 - d->pos_x) * d->delta_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->pos_y - d->ray_y) * d->delta_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->ray_y + 1 - d->pos_y) * d->delta_y;
	}
}

static void		set_wall_dist(t_data *d, int x)
{
	if (d->side == 0 || d->side == 1)
		d->wall_dist = (d->ray_x - d->pos_x +
			(1 - d->step_x) / 2) / d->ray_dir_x;
	else
		d->wall_dist = (d->ray_y - d->pos_y +
			(1 - d->step_y) / 2) / d->ray_dir_y;
	d->z_buffer[x] = d->wall_dist;
}

static void		dda(t_data *d, int x)
{
	while (!d->hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_x;
			d->ray_x += d->step_x;
			d->side = (d->step_x == 1) ? 0 : 1;
		}
		else
		{
			d->side_dist_y += d->delta_y;
			d->ray_y += d->step_y;
			d->side = (d->step_y == 1) ? 2 : 3;
		}
		if (is_wall(d->map[d->ray_y][d->ray_x]))
			d->hit = 1;
		else if (is_sprite(d->map[d->ray_y][d->ray_x]))
			sprite_hit(d);
	}
	set_wall_dist(d, x);
}

void			raycast(t_data *d)
{
	int		x;

	x = 0;
	del_all_sprite(&d->spritelst);
	ft_bzero(d->z_buffer, sizeof(double) * d->screen_x);
	while (x < d->screen_x)
	{
		set_data(d, x);
		set_side_dist(d);
		dda(d, x);
		d->line_height = (int)(d->screen_y / d->wall_dist);
		d->draw_start = (-d->line_height / 2) + (d->screen_y / 2);
		if (d->draw_start < 0)
			d->draw_start = 0;
		d->draw_end = (d->line_height / 2) + (d->screen_y / 2);
		if (d->draw_end >= d->screen_y)
			d->draw_end = d->screen_y - 1;
		put_line_to_img(d, x);
		x++;
	}
	draw_sprite(d);
	if (d->inventory)
		draw_hud(d, get_hud(d));
	if (!d->save)
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	else
		bitmap(d);
}
