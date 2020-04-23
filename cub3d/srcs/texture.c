/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 20:16:22 by memartin          #+#    #+#             */
/*   Updated: 2020/04/23 19:48:04 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture		*get_texture(t_data *d)
{
	if (d->side == 0)
		return (&d->west_t);
	else if (d->side == 1)
		return (&d->east_t);
	else if (d->side == 2)
		return (&d->north_t);
	else
		return (&d->south_t);
}

static void		put_pxl_texture(t_data *d, t_texture *t, int x, int y)
{
	d->text_y = (int)d->text_pos & (t->width - 1);
	d->text_pos += d->step;
	d->img_data[y * d->s_l + x * d->bpp / 8] =
		t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8];
	d->img_data[y * d->s_l + x * d->bpp / 8 + 1] =
		t->data[d->text_y * t->s_l + d->text_x * (t->bpp / 8) + 1];
	d->img_data[y * d->s_l + x * d->bpp / 8 + 2] =
		t->data[d->text_y * t->s_l + d->text_x * (t->bpp / 8) + 2];
}

void			put_texture_on_img(t_data *d, int x, t_texture *t)
{
	int		y;

	y = d->draw_start;
	if (d->side == 0 || d->side == 1)
		d->wall_x = (double)d->pos_y + d->wall_dist * d->ray_dir_y;
	else
		d->wall_x = (double)d->pos_x + d->wall_dist * d->ray_dir_x;
	d->wall_x -= floor(d->wall_x);
	d->text_x = (int)(d->wall_x * t->width);
	if ((d->side == 0 || d->side == 1) && d->ray_dir_x > 0)
		d->text_x = t->width - d->text_x - 1;
	if ((d->side == 2 || d->side == 3) && d->ray_dir_y < 0)
		d->text_x = t->width - d->text_x - 1;
	d->step = 1.0 * t->width / d->line_height;
	d->text_pos = (d->draw_start - d->screen_y / 2 +
			d->line_height / 2) * d->step;
	while (y <= d->draw_end)
	{
		put_pxl_texture(d, t, x, y);
		y++;
	}
}
