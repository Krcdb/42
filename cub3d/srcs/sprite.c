/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 15:31:41 by memartin          #+#    #+#             */
/*   Updated: 2020/04/19 18:39:21 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_spritelist	*new_sprite(t_data *d)
{
	t_spritelist		*new;

	if (!(new = (t_spritelist*)malloc(sizeof(t_spritelist))))
		return (NULL);
	new->map_x = d->ray_x;
	new->map_y = d->ray_y;
	new->dist = ((d->pos_x - new->map_x) * (d->pos_x - new->map_x)) +
		((d->pos_y - new->map_y) * (d->pos_y - new->map_y));
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

void				print_sprite(t_spritelist *hlst)
{
	int i = 0;

	printf("print sprite \n");
	if (hlst == NULL)
	{
		printf("no sprite\n");
		return ;
	}
	while (hlst)
	{
		printf("nb : %d | map_x : %d | map_y : %d | dist : %f\n", 
				hlst->nb_sprite, hlst->map_x, hlst->map_y, hlst->dist);
		hlst = hlst->next;
	}
	printf("\n");
}

void				del_all_sprite(t_spritelist **hlst)
{
	t_spritelist	*tmp;

	if (hlst == NULL || *hlst == NULL)
		return ;
	while ((*hlst)->next)
	{
		tmp = (*hlst)->next;
		free(*hlst);
		*hlst = tmp;
	}
	free(*hlst);
	*hlst = NULL;
}

void				sprite_hit(t_data *d)
{
	t_spritelist	*tmp;

	tmp = d->spritelst;
	while (tmp)
	{
		if (tmp->map_x == d->ray_x && tmp->map_y == d->ray_y)
			return ;
		tmp = tmp->next;
	}
	add_sprite(&d->spritelst, new_sprite(d));
	if (d->spritelst->next)
		d->spritelst->nb_sprite = d->spritelst->next->nb_sprite + 1;
	else
		d->spritelst->nb_sprite = 1;
}

static void		swap_sprite(t_spritelist **sprite1, t_spritelist **sprite2)
{
	double	tmp;
	int		tmp2;
	
	if ((*sprite1)->dist < (*sprite2)->dist)
	{
		tmp = (*sprite1)->dist;
		(*sprite1)->dist = (*sprite2)->dist;
		(*sprite2)->dist = tmp;
		tmp2 = (*sprite1)->map_x;
		(*sprite1)->map_x = (*sprite2)->map_x;
		(*sprite2)->map_x = tmp2;
		tmp2 = (*sprite1)->map_y;
		(*sprite1)->map_y = (*sprite2)->map_y;
		(*sprite2)->map_y = tmp2;
	}
}
void			sort_sprite(t_spritelist **spritelst)
{
	int				i;
	int				nb;
	t_spritelist	*lst;

	i = 0;
	nb = (*spritelst)->nb_sprite;
	lst = *spritelst;
	if (nb == 1)
		return ;
	if (nb == 2)
		swap_sprite(&lst, &lst->next);
	while (i < nb - 1)
	{
		lst = *spritelst;
		while (lst->next)
		{
			swap_sprite(&lst, &lst->next);
			lst = lst->next;
		}
		i++;
	}
}
