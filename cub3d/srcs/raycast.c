#include "../includes/cub3d.h"

static void		set_data(t_data *d, int x)
{
	d->camera_x = (2 * x / (double)(d->screen_x)) - 1;
	d->ray_dir_x = d->dir_x + d->plane_x * d->camera_x;
	d->ray_dir_y = d->dir_y + d->plane_y * d->camera_x;
	d->delta_x = sqrt(1 + (d->ray_dir_y * d->ray_dir_y) / (d->ray_dir_x * d->ray_dir_x));
	d->delta_y = sqrt(1 + (d->ray_dir_x * d->ray_dir_x) / (d->ray_dir_y * d->ray_dir_y));
	d->side_dist_x = 0;
	d->side_dist_y = 0;
	d->wall_dist = 0;
	d->ray_x = (int)d->pos_x;
	d->ray_y = (int)d->pos_y;
	d->step_x = 0;
	d->step_y = 0;
	d->hit = 0;
	d->side = 0;
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

static void		dda(t_data *d)
{
	while (!d->hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_x;
			d->ray_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_y;
			d->ray_y += d->step_y;
			d->side = 1;
		}
		if (d->map[d->ray_y][d->ray_x] == '1')
			d->hit = 1;
	}
	if (d->side == 0)
		d->wall_dist = (d->ray_x - d->pos_x + (1 - d->step_x) / 2) / d->ray_dir_x;
	else
		d->wall_dist = (d->ray_y - d->pos_y + (1 - d->step_y) / 2) / d->ray_dir_y;
}

void			raycast(t_data *d)
{
	int		x;

	x = 0;
	while (d->screen_x - 1 - x >= 0)
	{
		set_data(d, d->screen_x - 1 - x);
		set_side_dist(d);
		dda(d);
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
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}
