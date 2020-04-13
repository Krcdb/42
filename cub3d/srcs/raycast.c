#include "../includes/cub3d.h"

static void		set_data(t_data *d, int x)
{
	d->camera_x = 2 * x / (double)(d->screen_x) - 1;
	d->ray_dir_x = d->dir_x + d->plane_x * d->camera_x;
	d->ray_dir_y = d->dir_y + d->plane_y * d->camera_x;
	d->delta_x = abs(1 / d->ray_dir_x);
	d->delta_y = abs(1 / d->ray_dir_y);
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
		if (d->map[d->ray_y][d->ray_x] > 0)
			d->hit = 1;
	}
	if (d->side == 0)
		d->wall_dist = (d->ray_x - d->pos_x + (1 - d->step_x) / 2) / d->ray_dir_x;
	else
		d->wall_dist = (d->ray_y - d->pos_y + (1 - d->step_y) / 2) / d->ray_dir_y;
}

static int		get_color(t_data *d)
{
	if (d->side == 0)
	{
		if ((int)d->pos_x < d->ray_x)
			return (W_C);
		else
			return (E_C);
	}
	else
	{
		if ((int)d->pos_y < d->ray_y)
			return (NO_C);
		else
			return (SO_C);
	}
}

static void		draw_line(t_data *d, int x)
{
	int		y;
	int		color;

	y = 0;
	color = get_color(d);
	while (y < d->screen_y)
	{
		if (y < d->draw_start)
			mlx_pixel_put(d->mlx_ptr, d->win_ptr, x, y, d->c_color);
		else if (y >= d->draw_start && y <= d->draw_end)
			mlx_pixel_put(d->mlx_ptr, d->win_ptr, x, y, color);
		else
			mlx_pixel_put(d->mlx_ptr, d->win_ptr, x, y, d->f_color);
		y++;
	}
}

void			raycast(t_data *d)
{
	int		x;

	x = 0;
	printf("start raycast\n");
	while (x < d->screen_x)
	{
		set_data(d, x);
		set_side_dist(d);
		dda(d);
		d->line_height = (int)(d->screen_y / d->wall_dist);
		d->draw_start = (-d->line_height / 2) + (d->screen_y / 2);
		if (d->draw_start < 0)
			d->draw_start = 0;
		d->draw_end = (d->line_height / 2) + (d->screen_y / 2);
		if (d->draw_end >= d->screen_y)
			d->draw_end = d->screen_y - 1;
		draw_line(d, x);
		x++;
	}
}
