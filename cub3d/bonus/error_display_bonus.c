/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:49:33 by memartin          #+#    #+#             */
/*   Updated: 2020/04/30 11:51:02 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		error_display_1(t_data *d)
{
	if (d->error.e_memory)
		ft_printf("memory error\n");
	else if (d->error.e_missing)
		ft_printf("missing error\n");
	else if (d->error.e_file)
		ft_printf("file.cub error\n");
}

void			error_display(t_data *d)
{
	ft_printf("error\n");
	if (d->error.e_screen_res)
		ft_printf("screen resolution error\n");
	else if (d->error.e_no_t)
		ft_printf("north texture error\n");
	else if (d->error.e_so_t)
		ft_printf("south texture error\n");
	else if (d->error.e_we_t)
		ft_printf("west texture error\n");
	else if (d->error.e_ea_t)
		ft_printf("east texture error\n");
	else if (d->error.e_s_t)
		ft_printf("sprite texture error\n");
	else if (d->error.e_f_color)
		ft_printf("floor color error\n");
	else if (d->error.e_c_color)
		ft_printf("c color error\n");
	else if (d->error.e_fd)
		ft_printf("fd error\n");
	else if (d->error.e_map)
		ft_printf("map error\n");
	else
		error_display_1(d);
}
