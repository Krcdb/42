/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:29:07 by memartin          #+#    #+#             */
/*   Updated: 2020/04/23 23:25:13 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_sprite_draw(t_spritelist **sp, t_data *d)
{
	double		sp_x;
	double		sp_y;
	double		inv_det;

	sp_x = (*sp)->map_x - (d->pos_x - 0.5);
	sp_y = (*sp)->map_y - (d->pos_y - 0.5);
	inv_det = 1.0 / (d->plane_x * d->dir_y - d->dir_x * d->plane_y);
	(*sp)->transform_x = inv_det * (d->dir_y * sp_x - d->dir_x * sp_y);
	(*sp)->transform_y = inv_det * (-d->plane_y * sp_x + d->plane_x * sp_y);
	(*sp)->screen_x = (int)((d->screen_x / 2) *
		(1 + ((*sp)->transform_x / (*sp)->transform_y)));
	(*sp)->height = abs((int)(d->screen_y / (*sp)->transform_y));
	(*sp)->draw_start_y = (-(*sp)->height / 2) + (d->screen_y / 2);
	(*sp)->draw_start_y = ((*sp)->draw_start_y < 0) ? 0 : (*sp)->draw_start_y;
	(*sp)->draw_end_y = ((*sp)->height / 2) + (d->screen_y / 2);
	(*sp)->draw_end_y = ((*sp)->draw_end_y >= d->screen_y) ?
		d->screen_y - 1 : (*sp)->draw_end_y;
	(*sp)->width = abs((int)(d->screen_y / (*sp)->transform_y));
	(*sp)->draw_start_x = (-(*sp)->width / 2) + ((*sp)->screen_x);
	(*sp)->draw_start_x = ((*sp)->draw_start_x < 0) ? 0 : (*sp)->draw_start_x;
	(*sp)->draw_end_x = ((*sp)->width / 2) + ((*sp)->screen_x);
	(*sp)->draw_end_x = ((*sp)->draw_end_x >= d->screen_x) ?
		d->screen_x - 1 : (*sp)->draw_end_x;
}

static int		check_color(t_data *d, t_texture *t)
{
	if (t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8] == -1
		&& t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8 + 1] == 0
		&& t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8 + 2] == -1)
		return (0);
	return (1);
}

static void		put_p(int x, int y, t_data *d, t_texture *t)
{
	d->img_data[y * d->s_l + x * d->bpp / 8] =
		t->data[d->text_y * t->s_l + d->text_x * t->bpp / 8];
	d->img_data[y * d->s_l + x * d->bpp / 8 + 1] =
		t->data[d->text_y * t->s_l + d->text_x * (t->bpp / 8) + 1];
	d->img_data[y * d->s_l + x * d->bpp / 8 + 2] =
		t->data[d->text_y * t->s_l + d->text_x * (t->bpp / 8) + 2];
}

static void		draw_stripe(int x, t_spritelist *sp, t_data *d, t_texture *t)
{
	int		y;
	int		dd;

	d->text_x = (int)(t->s_l * (x - (-(sp->width) / 2 + sp->screen_x))
			* t->width / sp->width) / t->s_l;
	if (sp->transform_y > 0 && x > 0 && x < d->screen_x &&
		sp->transform_y < d->z_buffer[x])
	{
		y = sp->draw_start_y;
		while (y < sp->draw_end_y)
		{
			dd = (y * t->s_l) - d->screen_y * (t->s_l / 2)
				+ sp->height * t->s_l / 2;
			d->text_y = ((dd * t->height) / sp->height) / t->s_l;
			if (check_color(d, t))
				put_p(x, y, d, t);
			y++;
		}
	}
}

void			draw_sprite(t_data *d)
{
	int		x;

	if (d->spritelst == NULL)
		return ;
	sort_sprite(&d->spritelst);
	while (d->spritelst)
	{
		set_sprite_draw(&d->spritelst, d);
		x = d->spritelst->draw_start_x;
		while (x < d->spritelst->draw_end_x)
		{
			draw_stripe(x, d->spritelst, d, &d->sprite_t);
			x++;
		}
		d->spritelst = d->spritelst->next;
	}
}
