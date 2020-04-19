/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:29:07 by memartin          #+#    #+#             */
/*   Updated: 2020/04/19 20:29:26 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_sprite_draw(t_spritelist **sp, t_data *d)
{
	double		sp_x;
	double		sp_y;
	double		inv_det;

	sp_x = (*sp)->map_x + 0.5 - d->pos_x;
	sp_y = (*sp)->map_y + 0.5 - d->pos_y;
	inv_det = 1.0 / ( d->plane_x * d->dir_y - d->dir_x * d->plane_y);
	(*sp)->transform_x = inv_det * (d->dir_y * sp_x - d->dir_x * sp_y);
	(*sp)->transform_y = inv_det * (-d->plane_y * sp_x + d->plane_x * sp_y);
	(*sp)->screen_x = (int)((d->screen_x / 2) *
		(1 + (*sp)->transform_x / (*sp)->transform_y));
	(*sp)->height = abs((int)(d->screen_y / (*sp)->transform_y));
	(*sp)->draw_start_y = -(*sp)->height / 2  + d->screen_y / 2;
	(*sp)->draw_start_y = ((*sp)->draw_start_y < 0) ? 0 : (*sp)->draw_start_y;
	(*sp)->draw_end_y = (*sp)->height / 2  + d->screen_y / 2;
	(*sp)->draw_end_y = ((*sp)->draw_end_y >= d->screen_y) ? 
		d->screen_y - 1 : (*sp)->draw_end_y;
	(*sp)->width = abs((int)(d->screen_y / (*sp)->transform_y));
	(*sp)->draw_start_x = -(*sp)->width / 2  + (*sp)->screen_x / 2;
	(*sp)->draw_start_x = ((*sp)->draw_start_x < 0) ? 0 : (*sp)->draw_start_x;
	(*sp)->draw_end_x = (*sp)->width / 2  + (*sp)->screen_x / 2;
	(*sp)->draw_end_x = ((*sp)->draw_end_x >= d->screen_x) ? 
		d->screen_x - 1 : (*sp)->draw_end_x;
}

static void		draw_stripe(int x, t_spritelist *sp, t_data *d, t_texture *t)
{
	int		text_x;
	int		text_y;
	int		y;
	int		dd;
	
	if (sp->transform_y > 0 && x > 0 && x < d->screen_x && sp->transform_y < d->z_buffer[x])
	{
		text_x = (int)(256 * (x - (-sp->width / 2 + sp->screen_x))
			* d->sprite_t.width / sp->width) / 256;
		y = sp->draw_start_y;
		while (y < sp->draw_end_y)
		{
			dd = y * 256 - d->screen_y * 128 + sp->height * 128;
			text_y = ((dd * d->sprite_t.height) / sp->height) / 256;
			d->text_y = (int)d->text_pos & (t->width - 1);
			d->text_pos += d->step;
			d->img_data[y * d->s_l + x * d->bpp / 8] = 
				t->data[text_y * t->s_l + text_x * t->bpp / 8];
			d->img_data[y * d->s_l + x * d->bpp / 8 + 1] = 
				t->data[text_y * t->s_l + text_x * (t->bpp / 8) + 1];
			d->img_data[y * d->s_l + x * d->bpp / 8 + 2] = 
				t->data[text_y * t->s_l + text_x * (t->bpp / 8) + 2];
			y++;
		}
	}
}


void				draw_sprite(t_data *d)
{
	int		x;

	if (d->spritelst == NULL)
		return ;
	sort_sprite(&d->spritelst);
	//print_sprite(d->spritelst);
	while (d->spritelst)
	{
		set_sprite_draw(&d->spritelst, d);
		x = d->spritelst->draw_start_x;
		//printf("sp no : %d | x : %d | end_x : %d\n", d->spritelst->nb_sprite, x,
		//	d->spritelst->draw_end_x);
		while (x < d->spritelst->draw_end_x)
		{	
			draw_stripe(x, d->spritelst, d, &d->sprite_t);
			x++;
		}
		d->spritelst = d->spritelst->next;
	}
}
