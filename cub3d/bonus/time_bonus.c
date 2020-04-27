/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:12:27 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 10:47:39 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void			update_bool_time(t_data *d)
{
	d->diff_time = get_diff_time(d->old_time);
	if (d->diff_time > 0.4)
	{
		d->b_player_shooted = 0;
		d->b_player_spistol = 0;
	}
}

float			get_diff_time(clock_t old)
{
	return (((float)clock() - (float)old) / CLOCKS_PER_SEC);
}
