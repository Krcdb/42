#include "../includes/cub3d.h"

static void		init_textures(t_data *d)
{
	d->north_t.img = mlx_xpm_file_to_image(d->mlx_ptr, d->north_path,
		&d->north_t.width, &d->north_t.height);
	d->north_t.data = mlx_get_data_addr(d->north_t.img,
		&d->north_t.bpp, &d->north_t.s_l, &d->north_t.endian);
	d->south_t.img = mlx_xpm_file_to_image(d->mlx_ptr, d->south_path,
		&d->south_t.width, &d->south_t.height);
	d->south_t.data = mlx_get_data_addr(d->south_t.img, 
		&d->south_t.bpp, &d->south_t.s_l, &d->south_t.endian);
	d->west_t.img = mlx_xpm_file_to_image(d->mlx_ptr, d->west_path,
		&d->west_t.width, &d->west_t.height);
	d->west_t.data = mlx_get_data_addr(d->west_t.img, 
		&d->west_t.bpp, &d->west_t.s_l, &d->west_t.endian);
	d->east_t.img = mlx_xpm_file_to_image(d->mlx_ptr, d->east_path,
		&d->east_t.width, &d->east_t.height);
	d->east_t.data = mlx_get_data_addr(d->east_t.img,
		&d->east_t.bpp, &d->east_t.s_l, &d->east_t.endian);
	d->sprite_t.img = mlx_xpm_file_to_image(d->mlx_ptr, d->sprite_path,
		&d->sprite_t.width, &d->sprite_t.height);
	d->sprite_t.data = mlx_get_data_addr(d->sprite_t.img,
		&d->sprite_t.bpp, &d->sprite_t.s_l, &d->sprite_t.endian);
}

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
	d->speed = 0.04;
	d->rotation = 0.02;
	init_textures(d);
}

void			main_loop(t_data *d)
{
	d->mlx_ptr = mlx_init();
	init_data_game(d);
	d->img_ptr = mlx_new_image(d->mlx_ptr, d->screen_x, d->screen_y);
	d->img_data = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->s_l, &d->endian);
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->screen_x, d->screen_y, "cub3d");
	raycast(d);
	mlx_hook(d->win_ptr, 2, 1L << 0, event_key_pressed, d);
	mlx_hook(d->win_ptr, 3, 1L << 1, event_key_released, d);
	mlx_hook(d->win_ptr, 17, 1L << 17, exit_game, d);
	mlx_loop_hook(d->mlx_ptr, loop_manager, d);
	mlx_loop(d->mlx_ptr);
}
