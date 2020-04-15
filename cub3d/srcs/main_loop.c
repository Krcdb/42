#include "../includes/cub3d.h"

static void		init_data_game(t_data *d)
{
	d->plane_x = 0;
	d->plane_y = 0.66;
	d->dir_x = -1;
	d->dir_y = 0;
	d->pos_x = (double)d->player_x + 0.5;
	d->pos_y = (double)d->player_y + 0.5;
	if (d->screen_x > 1920)
		d->screen_x = 1920;
	if (d->screen_y > 1200)
		d->screen_y = 1200;
	d->strafe_left = 0;
	d->strafe_right = 0;
	d->move_forward = 0;
	d->move_backward = 0;
	d->rotate_left = 0;
	d->rotate_right = 0;
	d->sprint = 0;
	d->exit_game = 0;
	d->speed = 0.05;
	d->rotation = 0.05;
}

void			main_loop(t_data *d)
{
	init_data_game(d);
	d->mlx_ptr = mlx_init();
	d->img_ptr = mlx_new_image(d->mlx_ptr, d->screen_x, d->screen_y);
	d->img_data = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->s_l, &d->endian);
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->screen_x, d->screen_y, "cub3d");
	raycast(d);
	mlx_hook(d->win_ptr, 2, 1L << 0, event_key_pressed, d);
	mlx_hook(d->win_ptr, 3, 1L << 1, event_key_released, d);
	mlx_hook(d->win_ptr, 17, 1L << 17, exit_game, d);
	mlx_loop_hook(d->mlx_ptr, loop_manager, d);	
	if (!d->exit_game)	
		mlx_loop(d->mlx_ptr);
}
