/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:29:07 by memartin          #+#    #+#             */
/*   Updated: 2020/04/19 18:40:13 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				draw_sprite(t_data *d)
{
	if (d->spritelst == NULL)
		return ;
	sort_sprite(&d->spritelst);
	print_sprite(d->spritelst);
}
