/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:24:25 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 19:21:57 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				init_hud_textures(t_data *d)
{
	d->pistol_t.img = mlx_xpm_file_to_image(d->mlx_ptr, PISTOL_HUD_PATH,
		&d->pistol_t.width, &d->pistol_t.height);
	d->pistol_t.data = mlx_get_data_addr(d->pistol_t.img,
		&d->pistol_t.bpp, &d->pistol_t.s_l, &d->pistol_t.endian);
	d->pistol_t.draw_s_x = d->screen_x / 2;
	d->pistol_t.draw_e_x = d->screen_x / 2 + 0.234375 * d->screen_x;
	d->pistol_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->pistol_t.draw_e_y = d->screen_y - 1;
	d->shootgun_t.img = mlx_xpm_file_to_image(d->mlx_ptr, SHOOT_HUD_PATH,
		&d->shootgun_t.width, &d->shootgun_t.height);
	d->shootgun_t.data = mlx_get_data_addr(d->shootgun_t.img,
		&d->shootgun_t.bpp, &d->shootgun_t.s_l, &d->shootgun_t.endian);
	d->shootgun_t.draw_s_x = d->screen_x / 2;
	d->shootgun_t.draw_e_x = d->screen_x / 2 + 0.234375 * d->screen_x;
	d->shootgun_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->shootgun_t.draw_e_y = d->screen_y - 1;
	d->nuke_t.img = mlx_xpm_file_to_image(d->mlx_ptr, NUKE_HUD_PATH,
		&d->nuke_t.width, &d->nuke_t.height);
	d->nuke_t.data = mlx_get_data_addr(d->nuke_t.img,
		&d->nuke_t.bpp, &d->nuke_t.s_l, &d->nuke_t.endian);
	d->nuke_t.draw_s_x = d->screen_x / 2;
	d->nuke_t.draw_e_x = d->screen_x / 2 + (0.234375 * d->screen_x) * 2;
	d->nuke_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->nuke_t.draw_e_y = d->screen_y - 1;
	d->handcard_t.img = mlx_xpm_file_to_image(d->mlx_ptr, HANDCARD_PATH,
		&d->handcard_t.width, &d->handcard_t.height);
	d->handcard_t.data = mlx_get_data_addr(d->handcard_t.img,
		&d->handcard_t.bpp, &d->handcard_t.s_l, &d->handcard_t.endian);
	d->handcard_t.draw_s_x = d->screen_x / 2;
	d->handcard_t.draw_e_x = d->screen_x / 2 + (0.234375 * d->screen_x) * 2;
	d->handcard_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->handcard_t.draw_e_y = d->screen_y - 1;
	if (!d->shootgun_t.img || !d->pistol_t.img || !d->nuke_t.img ||
		!d->handcard_t.img)
		return (0);
	return (1);
}

t_hud			*get_hud(t_data *d)
{
	if (d->inventory == 1)
		return (&d->pistol_t);
	else if (d->inventory == 2)
		return (&d->shootgun_t);
	else if (d->inventory == 3)
		return (&d->nuke_t);
	else if (d->inventory == 4)
		return (&d->handcard_t);
	else
		return (NULL);
}

static int		check_color(t_data *d, t_hud *t)
{
	if (t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8] == -1
		&& t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8 + 1] == 0
		&& t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8 + 2] == -1)
		return (0);
	return (1);
}

static void		draw_hud_pxl(int x, int y, t_data *d, t_hud *t)
{
	d->text_y = ((double)(y - t->draw_s_y) / (double)(t->draw_e_y - t->draw_s_y)) * t->height;
	if (check_color(d, t))
	{
		d->img_data[y * d->s_l + x * d->bpp / 8] = 
			t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8];
		d->img_data[y * d->s_l + x * d->bpp / 8 + 1] = 
			t->data[d->text_y * t->s_l + d->text_x * (t->bpp / 8) + 1];
		d->img_data[y * d->s_l + x * d->bpp / 8 + 2] = 
			t->data[d->text_y * t->s_l + d->text_x * (t->bpp / 8) + 2];
	}
}

void			draw_hud(t_data *d, t_hud *t)
{
	int		x;
	int		y;
	
	x = t->draw_s_x;
	while (x < t->draw_e_x)
	{
		y = t->draw_s_y;
		d->text_x = ((double)(x - t->draw_s_x) / (double)(t->draw_e_x - t->draw_s_x)) *
			t->width;
		while (y < t->draw_e_y)
		{
			draw_hud_pxl(x, y, d, t);
			y++;
		}
		x++;
	}
}
