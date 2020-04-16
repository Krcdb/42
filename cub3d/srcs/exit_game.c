#include "../includes/cub3d.h"

static void		free_data(t_data *d)
{
	int		i;

	i = 0;
	while (d->map[i])
	{
		if (d->map[i])
			free(d->map[i]);
		i++;
	}
	if (d->map)
		free(d->map);
}

int				exit_game(void	*param)
{
	t_data *d;

	d = (t_data *)param;
	printf("exit game\n");
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	mlx_destroy_image(d->mlx_ptr, d->img_ptr);
	free_data(d);
	exit(0);
}
