/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 15:31:41 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:29:40 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static t_spritelist	*new_sprite(t_data *d, char c, int x)
{
	t_spritelist		*new;

	if (!(new = (t_spritelist*)malloc(sizeof(t_spritelist))))
		return (NULL);
	new->type = c;
	new->map_x = d->ray_x;
	new->map_y = d->ray_y;
	new->dist = ((d->pos_x - new->map_x) * (d->pos_x - new->map_x)) +
		((d->pos_y - new->map_y) * (d->pos_y - new->map_y));
	if (c == 'g')
	{
		new->draw_start_x = x;
		new->draw_end_x = x;
	}
	new->next = NULL;
	return (new);
}

static void			add_sprite(t_spritelist **hlst, t_spritelist *nlst)
{
	if (hlst != NULL && nlst != NULL)
	{
		nlst->next = *hlst;
		*hlst = nlst;
	}
}

void				sprite_hit(t_data *d, int x)
{
	t_spritelist	*tmp;

	tmp = d->spritelst;
	while (tmp)
	{
		if (tmp->map_x == d->ray_x && tmp->map_y == d->ray_y)
		{
			if (tmp->type == 'g')
				tmp->draw_end_x = x;
			return ;
		}
		tmp = tmp->next;
	}
	add_sprite(&d->spritelst, new_sprite(d, d->map[d->ray_y][d->ray_x], x));
	if (d->spritelst->next)
		d->spritelst->nb_sprite = d->spritelst->next->nb_sprite + 1;
	else
		d->spritelst->nb_sprite = 1;
}
