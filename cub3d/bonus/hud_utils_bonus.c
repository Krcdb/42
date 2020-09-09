/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:13:08 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 18:25:04 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int		init_hud_textures_1(t_data *d)
{
	d->pistol1_t.img = mlx_xpm_file_to_image(d->mlx_ptr, PISTOL1_HUD_PATH,
		&d->pistol1_t.width, &d->pistol1_t.height);
	if (d->pistol1_t.img)
		d->pistol1_t.data = mlx_get_data_addr(d->pistol1_t.img,
			&d->pistol1_t.bpp, &d->pistol1_t.s_l, &d->pistol1_t.endian);
	d->pistol1_t.draw_s_x = d->screen_x / 2;
	d->pistol1_t.draw_e_x = d->screen_x / 2 + 0.234375 * d->screen_x;
	d->pistol1_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->pistol1_t.draw_e_y = d->screen_y - 1;
	d->pistol2_t.img = mlx_xpm_file_to_image(d->mlx_ptr, PISTOL2_HUD_PATH,
		&d->pistol2_t.width, &d->pistol2_t.height);
	if (d->pistol2_t.img)
		d->pistol2_t.data = mlx_get_data_addr(d->pistol2_t.img,
			&d->pistol2_t.bpp, &d->pistol2_t.s_l, &d->pistol2_t.endian);
	d->pistol2_t.draw_s_x = d->screen_x / 2;
	d->pistol2_t.draw_e_x = d->screen_x / 2 + 0.234375 * d->screen_x;
	d->pistol2_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->pistol2_t.draw_e_y = d->screen_y - 1;
	if (!d->pistol1_t.img || !d->pistol2_t.img)
		return (0);
	return (1);
}

static int		init_hud_textures_2(t_data *d)
{
	d->nuke_t.img = mlx_xpm_file_to_image(d->mlx_ptr, NUKE_HUD_PATH,
		&d->nuke_t.width, &d->nuke_t.height);
	if (d->nuke_t.img)
		d->nuke_t.data = mlx_get_data_addr(d->nuke_t.img,
			&d->nuke_t.bpp, &d->nuke_t.s_l, &d->nuke_t.endian);
	d->nuke_t.draw_s_x = d->screen_x / 2;
	d->nuke_t.draw_e_x = d->screen_x / 2 + (0.234375 * d->screen_x) * 2;
	d->nuke_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->nuke_t.draw_e_y = d->screen_y - 1;
	d->handcard_t.img = mlx_xpm_file_to_image(d->mlx_ptr, HANDCARD_PATH,
		&d->handcard_t.width, &d->handcard_t.height);
	if (d->handcard_t.img)
		d->handcard_t.data = mlx_get_data_addr(d->handcard_t.img,
			&d->handcard_t.bpp, &d->handcard_t.s_l, &d->handcard_t.endian);
	d->handcard_t.draw_s_x = d->screen_x / 2;
	d->handcard_t.draw_e_x = d->screen_x / 2 + (0.234375 * d->screen_x) * 2;
	d->handcard_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->handcard_t.draw_e_y = d->screen_y - 1;
	if (!d->nuke_t.img || !d->handcard_t.img)
		return (0);
	return (1);
}

int				init_hud_textures(t_data *d)
{
	d->pistol_t.img = mlx_xpm_file_to_image(d->mlx_ptr, PISTOL_HUD_PATH,
		&d->pistol_t.width, &d->pistol_t.height);
	if (d->pistol_t.img)
		d->pistol_t.data = mlx_get_data_addr(d->pistol_t.img,
			&d->pistol_t.bpp, &d->pistol_t.s_l, &d->pistol_t.endian);
	d->pistol_t.draw_s_x = d->screen_x / 2;
	d->pistol_t.draw_e_x = d->screen_x / 2 + 0.234375 * d->screen_x;
	d->pistol_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->pistol_t.draw_e_y = d->screen_y - 1;
	d->shootgun_t.img = mlx_xpm_file_to_image(d->mlx_ptr, SHOOT_HUD_PATH,
		&d->shootgun_t.width, &d->shootgun_t.height);
	if (d->shootgun_t.img)
		d->shootgun_t.data = mlx_get_data_addr(d->shootgun_t.img,
			&d->shootgun_t.bpp, &d->shootgun_t.s_l, &d->shootgun_t.endian);
	d->shootgun_t.draw_s_x = d->screen_x / 2;
	d->shootgun_t.draw_e_x = d->screen_x / 2 + 0.234375 * d->screen_x;
	d->shootgun_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->shootgun_t.draw_e_y = d->screen_y - 1;
	if (!d->shootgun_t.img || !d->pistol_t.img ||
		!init_hud_textures_1(d) || !init_hud_textures_2(d))
		return (0);
	return (1);
}
