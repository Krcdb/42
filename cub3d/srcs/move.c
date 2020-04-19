#include "../includes/cub3d.h"

void		strafe_left(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x + d->plane_x * d->speed)] == '0')
		d->pos_x += d->plane_x * d->speed;
	if (d->map[(int)(d->pos_y + d->plane_y * d->speed)][(int)d->pos_x] == '0')
		d->pos_y += d->plane_y * d->speed;
}

void		strafe_right(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x - d->plane_x * d->speed)] == '0')
		d->pos_x -= d->plane_x * d->speed;
	if (d->map[(int)(d->pos_y - d->plane_y * d->speed)][(int)d->pos_x] == '0')
		d->pos_y -= d->plane_y * d->speed;
}

void		move_forward(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x + d->dir_x * d->speed)] == '0')
		d->pos_x += d->dir_x * d->speed;
	if (d->map[(int)(d->pos_y + d->dir_y * d->speed)][(int)d->pos_x] == '0')
		d->pos_y += d->dir_y * d->speed;
}

void		move_backward(t_data *d)
{
	if (d->map[(int)d->pos_y][(int)(d->pos_x - d->dir_x * d->speed)] == '0')
		d->pos_x -= d->dir_x * d->speed;
	if (d->map[(int)(d->pos_y - d->dir_y * d->speed)][(int)d->pos_x] == '0')
		d->pos_y -= d->dir_y * d->speed;
}

void		rotate_left(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->dir_x;
	old_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(d->rotation) - d->dir_y * sin(d->rotation);
	d->dir_y = old_dir_x * sin(d->rotation) + d->dir_y * cos(d->rotation);
	d->plane_x = d->plane_x * cos(d->rotation) - d->plane_y * sin(d->rotation);
	d->plane_y = old_plane_x * sin(d->rotation) + d->plane_y * cos(d->rotation);
}

void		rotate_right(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->dir_x;
	old_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(-d->rotation) - d->dir_y * sin(-d->rotation);
	d->dir_y = old_dir_x * sin(-d->rotation) + d->dir_y * cos(-d->rotation);
	d->plane_x = d->plane_x * cos(-d->rotation) - d->plane_y * sin(-d->rotation);
	d->plane_y = old_plane_x * sin(-d->rotation) + d->plane_y * cos(-d->rotation);
}
