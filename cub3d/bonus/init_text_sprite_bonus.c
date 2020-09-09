/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_sprite_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:35:14 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:12:01 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				init_wall_text(t_data *d)
{
	d->exit_t.img = mlx_xpm_file_to_image(d->mlx_ptr, EXIT_PATH,
		&d->exit_t.width, &d->exit_t.height);
	if (d->exit_t.img)
		d->exit_t.data = mlx_get_data_addr(d->exit_t.img,
			&d->exit_t.bpp, &d->exit_t.s_l, &d->exit_t.endian);
	d->secret_t.img = mlx_xpm_file_to_image(d->mlx_ptr, SECRET_PATH,
		&d->secret_t.width, &d->secret_t.height);
	if (d->secret_t.img)
		d->secret_t.data = mlx_get_data_addr(d->secret_t.img,
			&d->secret_t.bpp, &d->secret_t.s_l, &d->secret_t.endian);
	d->lock_t.img = mlx_xpm_file_to_image(d->mlx_ptr, LOCKED_PATH,
		&d->lock_t.width, &d->lock_t.height);
	if (d->lock_t.img)
		d->lock_t.data = mlx_get_data_addr(d->lock_t.img,
			&d->lock_t.bpp, &d->lock_t.s_l, &d->lock_t.endian);
	d->door_t.img = mlx_xpm_file_to_image(d->mlx_ptr, DOOR_PATH,
		&d->door_t.width, &d->door_t.height);
	if (d->door_t.img)
		d->door_t.data = mlx_get_data_addr(d->door_t.img,
			&d->door_t.bpp, &d->door_t.s_l, &d->door_t.endian);
	if (!d->exit_t.img || !d->secret_t.img || !d->door_t.img || !d->lock_t.img)
		return (0);
	return (1);
}

static int		init_sprite_text_1(t_data *d)
{
	d->deadmob_t.img = mlx_xpm_file_to_image(d->mlx_ptr, DEAD_PATH,
		&d->deadmob_t.width, &d->deadmob_t.height);
	if (d->deadmob_t.img)
		d->deadmob_t.data = mlx_get_data_addr(d->deadmob_t.img,
			&d->deadmob_t.bpp, &d->deadmob_t.s_l, &d->deadmob_t.endian);
	d->pistoldrop_t.img = mlx_xpm_file_to_image(d->mlx_ptr, PISTOL_DROP_PATH,
		&d->pistoldrop_t.width, &d->pistoldrop_t.height);
	if (d->pistoldrop_t.img)
		d->pistoldrop_t.data = mlx_get_data_addr(d->pistoldrop_t.img,
			&d->pistoldrop_t.bpp, &d->pistoldrop_t.s_l,
			&d->pistoldrop_t.endian);
	d->shootdrop_t.img = mlx_xpm_file_to_image(d->mlx_ptr, SHOOT_DROP_PATH,
		&d->shootdrop_t.width, &d->shootdrop_t.height);
	if (d->shootdrop_t.img)
		d->shootdrop_t.data = mlx_get_data_addr(d->shootdrop_t.img,
			&d->shootdrop_t.bpp, &d->shootdrop_t.s_l, &d->shootdrop_t.endian);
	d->nukedrop_t.img = mlx_xpm_file_to_image(d->mlx_ptr, NUKE_DROP_PATH,
		&d->nukedrop_t.width, &d->nukedrop_t.height);
	if (d->nukedrop_t.img)
		d->nukedrop_t.data = mlx_get_data_addr(d->nukedrop_t.img,
			&d->nukedrop_t.bpp, &d->nukedrop_t.s_l, &d->nukedrop_t.endian);
	if (!d->deadmob_t.img || !d->pistoldrop_t.img || !d->shootdrop_t.img ||
		!d->nukedrop_t.img)
		return (0);
	return (1);
}

int				init_sprite_text(t_data *d)
{
	d->glass_t.img = mlx_xpm_file_to_image(d->mlx_ptr, GLASS_PATH,
		&d->glass_t.width, &d->glass_t.height);
	if (d->glass_t.img)
		d->glass_t.data = mlx_get_data_addr(d->glass_t.img,
			&d->glass_t.bpp, &d->glass_t.s_l, &d->glass_t.endian);
	d->card_t.img = mlx_xpm_file_to_image(d->mlx_ptr, CARD_PATH,
		&d->card_t.width, &d->card_t.height);
	if (d->card_t.img)
		d->card_t.data = mlx_get_data_addr(d->card_t.img,
			&d->card_t.bpp, &d->card_t.s_l, &d->card_t.endian);
	if (!d->glass_t.img || !d->card_t.img || !init_sprite_text_1(d))
		return (0);
	return (1);
}
