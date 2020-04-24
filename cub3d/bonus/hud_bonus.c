/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:24:25 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:13:36 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				init_hud_textures(t_data *d)
{
	d->sgun_t.img = mlx_xpm_file_to_image(d->mlx_ptr, "./textures/sgun.xpm",
		&d->sgun_t.width, &d->sgun_t.height);
	d->sgun_t.data = mlx_get_data_addr(d->sgun_t.img,
		&d->sgun_t.bpp, &d->sgun_t.s_l, &d->sgun_t.endian);
	d->sgun_t.draw_s_x = d->screen_x / 2;
	d->sgun_t.draw_e_x = d->screen_x / 2 + 0.234375 * d->screen_x;
	d->sgun_t.draw_s_y = d->screen_y - 0.375 * d->screen_y - 1;
	d->sgun_t.draw_e_y = d->screen_y - 1;
	if (!d->sgun_t.img)
		return (0);
	return (1);
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
