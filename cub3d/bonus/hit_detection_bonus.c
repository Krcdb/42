/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:54:35 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 17:26:06 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				is_wall(char c)
{
	if (c == '1' || c == 'e' || c == 'h' || c == 'd' || c == 'l')
		return (1);
	return (0);
}

int				is_sprite(char c)
{
	if (c == 'm' || c == 'k' || c == 'p' || c == 's' || c == 'n' ||
		c == 'g' || c == 'c')
		return (1);
	return (0);
}

int				is_walk(char c)
{
	if (c == '0' || c == 'h' || c == 'k' || c == 'p' || c == 's' ||
		c == 'n' || c == 'c')
		return (1);
	return (0);
}
