/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:47:51 by user42            #+#    #+#             */
/*   Updated: 2020/04/23 18:57:10 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		init_error(t_data *d)
{
	d->error.e_screen_res = 0;
	d->error.e_no_t = 0;
	d->error.e_so_t = 0;
	d->error.e_we_t = 0;
	d->error.e_ea_t = 0;
	d->error.e_s_t = 0;
	d->error.e_f_color = 0;
	d->error.e_c_color = 0;
	d->error.e_fd = 0;
	d->error.e_file = 0;
	d->error.e_map = 0;
	d->error.e_memory = 0;
}

static void		data_display(t_data *d)
{
	printf("x = %d | y = %d\n", d->screen_x, d->screen_y);
	if (d->north_path)
		printf("no path = %s\n", d->north_path);
	else
		printf("no no_path\n");
	if (d->south_path)
		printf("so path = %s\n", d->south_path);
	else
		printf("no so_path\n");
	if (d->west_path)
		printf("we path = %s\n", d->west_path);
	else
		printf("no we_path\n");
	if (d->east_path)
		printf("ea path = %s\n", d->east_path);
	else
		printf("no ea_path\n");
	if (d->sprite_path)
		printf("s path = %s\n", d->sprite_path);
	else
		printf("no sprite_path\n");
	printf("f_color = %d | c_color = %d\n", d->f_color, d->c_color);
	printf("player start x : %d | player start y : %d\n",
	d->player_x, d->player_y);
}

static void		error_display(t_data *d)
{
	ft_printf("error\n");
	if (d->error.e_screen_res)
		printf("screen resolution error\n");
	else if (d->error.e_no_t)
		printf("north texture error\n");
	else if (d->error.e_so_t)
		printf("south texture error\n");
	else if (d->error.e_we_t)
		printf("west texture error\n");
	else if (d->error.e_ea_t)
		printf("east texture error\n");
	else if (d->error.e_s_t)
		printf("sprite texture error\n");
	else if (d->error.e_f_color)
		printf("floor color error\n");
	else if (d->error.e_c_color)
		printf("c color error\n");
	else if (d->error.e_fd)
		printf("fd error\n");
	else if (d->error.e_file)
		printf("file.cub error\n");
	else if (d->error.e_map)
		printf("map error\n");
}

static void		init_data(t_data *d)
{
	init_error(d);
	d->screen_x = 0;
	d->screen_y = 0;
	d->c_color = 0;
	d->f_color = 0;
	d->north_path = NULL;
	d->south_path = NULL;
	d->west_path = NULL;
	d->east_path = NULL;
	d->sprite_path = NULL;
	d->win_ptr = NULL;
	d->img_ptr = NULL;
	d->north_t.img = NULL;
	d->south_t.img = NULL;
	d->west_t.img = NULL;
	d->east_t.img = NULL;
	d->sprite_t.img = NULL;
	d->sgun_t.img = NULL;
	d->map = NULL;
	d->map_x = 0;
	d->map_y = 0;
	d->spritelst = NULL;
}

int				main(int ac, char **av)
{
	t_data d;

	if (ac < 2)
		ft_printf("error\nneed a file in arg\n");
	else if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		ft_printf("error\nbad option\n");
	else if (ac > 3)
		ft_printf("error\ntoo many arguments\n");
	else
	{
		if (ac == 3)
			d.save = 1;
		else
			d.save = 0;
		init_data(&d);
		if (parse(&d, av[1]))
			main_loop(&d);
		else
		{
			error_display(&d);
			exit_init(&d);
		}
	}
}
