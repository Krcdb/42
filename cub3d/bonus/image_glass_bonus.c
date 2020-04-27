/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_glass_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:44:17 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 11:59:28 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int			check_color(t_data *d, t_texture *t)
{
	if (t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8] == -1
		&& t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8 + 1] == 0
		&& t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8 + 2] == -1)
		return (0);
	return (1);
}

static void		put_pxl_texture(t_data *d, t_texture *t, int x, int y)
{
	d->text_y = (int)d->text_pos & (t->width - 1);
	d->text_pos += d->step;
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

void			put_glass_line_to_img(t_data *d, int x, t_texture *t)
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

