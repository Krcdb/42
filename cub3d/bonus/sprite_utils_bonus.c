/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:28:38 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:30:32 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void			swap_sprite_2(t_spritelist **sprite1,
	t_spritelist **sprite2)
{
	int		tmp;

	tmp = (*sprite1)->draw_start_x;
	(*sprite1)->draw_start_x = (*sprite2)->draw_start_x;
	(*sprite2)->draw_start_x = tmp;
	tmp = (*sprite1)->draw_end_x;
	(*sprite1)->draw_end_x = (*sprite2)->draw_end_x;
	(*sprite2)->draw_end_x = tmp;
}

static void			swap_sprite(t_spritelist **sprite1, t_spritelist **sprite2)
{
	double	tmp;
	int		tmp2;
	char	tmp3;

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
		tmp3 = (*sprite1)->type;
		(*sprite1)->type = (*sprite2)->type;
		(*sprite2)->type = tmp3;
		swap_sprite_2(sprite1, sprite2);
	}
}

void				sort_sprite(t_spritelist **spritelst)
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
