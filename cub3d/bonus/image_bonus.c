/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:56:22 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 15:49:56 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		put_pixel_to_img(t_data *d, int x, int y, int color)
{
	unsigned char *rgb;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	rgb = (unsigned char *)&color;
	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	d->img_data[y * d->s_l + x * d->bpp / 8] = r;
	d->img_data[y * d->s_l + x * d->bpp / 8 + 1] = g;
	d->img_data[y * d->s_l + x * d->bpp / 8 + 2] = b;
}

void			put_line_to_img(t_data *d, int x)
{
	int		y;

	y = 0;
	while (y < d->draw_start)
		put_pixel_to_img(d, x, y++, d->c_color);
	y = d->draw_end + 1;
	while (y < d->screen_y)
		put_pixel_to_img(d, x, y++, d->f_color);
	put_texture_on_img(d, x, get_texture(d, d->map[d->ray_y][d->ray_x]));
}
