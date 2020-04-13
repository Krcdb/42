#include "../includes/cub3d.h"

static void		init_data_game(t_data *d)
{
	d->plane_x = 0;
	d->plane_y = 0.66;
	d->dir_x = -1;
	d->dir_y = 0;
	d->pos_x = (double)d->player_x + 0.5;
	d->pos_y = (double)d->player_y + 0.5;
}

void			make_window(t_data *d)
{
	void *mlx;
	void *win;
	printf("start mlx\n");
	write(1, "1\n", 2);
	mlx = mlx_init();
	write(1, "1\n", 2);
	win = mlx_new_window(mlx, d->screen_x, d->screen_y, "cub3d");
	write(1, "1\n", 2);
	//init_data_game(d);
	//raycast(d);
	mlx_loop(mlx);
}
