/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:24:25 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 18:19:50 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_hud			*get_hud(t_data *d)
{
	d->diff_time = get_diff_time(d->old_time);
	if (d->inventory == 1)
	{
		if (!d->b_player_spistol)
			return (&d->pistol_t);
		if (d->diff_time < 0.15 && d->b_player_spistol)
			return (&d->pistol1_t);
		else if (d->diff_time < 0.3 && d->b_player_spistol)
			return (&d->pistol2_t);
		else
			return (&d->pistol_t);
	}
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
	d->text_y = ((double)(y - t->draw_s_y) /
		(double)(t->draw_e_y - t->draw_s_y)) * t->height;
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
		d->text_x = ((double)(x - t->draw_s_x) /
			(double)(t->draw_e_x - t->draw_s_x)) *
			t->width;
		while (y < t->draw_e_y)
		{
			draw_hud_pxl(x, y, d, t);
			y++;
		}
		x++;
	}
}
