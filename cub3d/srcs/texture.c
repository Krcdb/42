/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 20:16:22 by memartin          #+#    #+#             */
/*   Updated: 2020/04/18 18:55:33 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char			*get_texture_data(t_data *d)
{
	if (d->side == 0)
		return (d->ea_data);
	else if (d->side == 1)
		return (d->we_data);
	else if (d->side == 2)
		return (d->so_data);
	else
		return (d->no_data);
}

void			put_texture_on_img(t_data *d, int x, char *text_data)
{
	int		y;

	y = d->draw_start;
	if (d->side == 0 || d->side == 1)
		d->wall_x = (double)d->pos_y + d->wall_dist * d->ray_dir_y;
	else	
		d->wall_x = (double)d->pos_x + d->wall_dist * d->ray_dir_x;
	d->wall_x -= floor(d->wall_x);
	d->text_x = (int)(d->wall_x * 64);
	if ((d->side == 0 || d->side == 1) && d->ray_dir_x > 0)
		d->text_x = d->texture_size - d->text_x - 1;
	if ((d->side == 2 || d->side == 3) && d->ray_dir_y < 0)
		d->text_x = d->texture_size - d->text_x - 1;
	d->step = 1.0 * d->texture_size / d->line_height;
	d->text_pos = (d->draw_start - d->screen_y / 2 + d->line_height / 2) * d->step;
	while (y <= d->draw_end)
	{
		d->text_y = (int)d->text_pos & (d->texture_size - 1);
		d->text_pos += d->step;
		d->img_data[y * d->s_l + x * d->bpp / 8] = 
			text_data[d->text_y * d->t_s_l + d->text_x * d->t_bpp / 8];
		d->img_data[y * d->s_l + x * d->bpp / 8 + 1] = 
			text_data[d->text_y * d->t_s_l + d->text_x * (d->t_bpp / 8) + 1];
		d->img_data[y * d->s_l + x * d->bpp / 8 + 2] = 
			text_data[d->text_y * d->t_s_l + d->text_x * (d->t_bpp / 8) + 2];
		y++;
	}
}
