/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:59:18 by memartin          #+#    #+#             */
/*   Updated: 2020/04/30 14:53:42 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int		init_textures(t_data *d)
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
	d->mob_t.img = mlx_xpm_file_to_image(d->mlx_ptr, d->sprite_path,
		&d->mob_t.width, &d->mob_t.height);
	d->mob_t.data = mlx_get_data_addr(d->mob_t.img,
		&d->mob_t.bpp, &d->mob_t.s_l, &d->mob_t.endian);
	if (!d->north_t.img || !d->south_t.img || !d->west_t.img || !d->east_t.img
			|| !d->mob_t.img)
		return (0);
	return (1);
}

static void		init_move_key(t_data *d)
{
	d->strafe_left = 0;
	d->strafe_right = 0;
	d->move_forward = 0;
	d->move_backward = 0;
	d->rotate_left = 0;
	d->rotate_right = 0;
	d->sprint = 0;
	d->exit_game = 0;
	d->speed = 0.02;
	d->rotation = 0.01;
	d->b_one = 0;
	d->b_two = 0;
	d->b_three = 0;
	d->b_four = 0;
	d->b_action = 0;
}

static void		init_data_game(t_data *d)
{
	init_pos_camera(d);
	init_move_key(d);
	if (d->screen_x > 1920)
		d->screen_x = 1920;
	else if (d->screen_x < 640)
		d->screen_x = 640;
	if (d->screen_y > 1200)
		d->screen_y = 1200;
	else if (d->screen_y < 400)
		d->screen_y = 400;
	d->z_buffer = NULL;
	d->img_ptr = mlx_new_image(d->mlx_ptr, d->screen_x, d->screen_y);
	d->img_data = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->s_l, &d->endian);
	if (d->save != 1)
		d->win_ptr = mlx_new_window(d->mlx_ptr, d->screen_x,
		d->screen_y, "cub3d");
	if (!init_textures(d) || !d->img_ptr || !init_hud_textures(d) ||
		!init_wall_text(d) || !init_sprite_text(d) || (!d->win_ptr && !d->save))
		exit_game(d);
	if (!(d->z_buffer = (double*)malloc(sizeof(double) * d->screen_x)))
		exit_game(d);
}

void			main_loop(t_data *d)
{
	d->mlx_ptr = mlx_init();
	init_data_game(d);
	raycast(d);
	mlx_hook(d->win_ptr, 2, 1L << 0, event_key_pressed, d);
	mlx_hook(d->win_ptr, 3, 1L << 1, event_key_released, d);
	mlx_hook(d->win_ptr, 17, 1L << 17, exit_game, d);
	mlx_loop_hook(d->mlx_ptr, loop_manager, d);
	mlx_loop(d->mlx_ptr);
}
