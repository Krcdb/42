/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:56:40 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:13:50 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			loop_manager(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	raycast(d);
	key_manager(d);
	return (1);
}
