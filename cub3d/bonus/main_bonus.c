/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:47:51 by user42            #+#    #+#             */
/*   Updated: 2020/04/30 11:51:17 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
	d->error.e_missing = 0;
}

static void		init_text_null(t_data *d)
{
	d->north_t.img = NULL;
	d->south_t.img = NULL;
	d->west_t.img = NULL;
	d->east_t.img = NULL;
	d->exit_t.img = NULL;
	d->secret_t.img = NULL;
	d->lock_t.img = NULL;
	d->door_t.img = NULL;
	d->mob_t.img = NULL;
	d->deadmob_t.img = NULL;
	d->pistoldrop_t.img = NULL;
	d->shootdrop_t.img = NULL;
	d->nukedrop_t.img = NULL;
	d->glass_t.img = NULL;
	d->card_t.img = NULL;
	d->pistol_t.img = NULL;
	d->pistol1_t.img = NULL;
	d->pistol2_t.img = NULL;
	d->shootgun_t.img = NULL;
	d->nuke_t.img = NULL;
	d->handcard_t.img = NULL;
	d->north_path = NULL;
	d->south_path = NULL;
	d->west_path = NULL;
	d->east_path = NULL;
}

static void		init_data(t_data *d)
{
	init_error(d);
	d->screen_x = 0;
	d->screen_y = 0;
	d->c_color = 0;
	d->f_color = 0;
	d->sprite_path = NULL;
	d->win_ptr = NULL;
	d->img_ptr = NULL;
	d->map = NULL;
	d->map_x = 0;
	d->map_y = 0;
	d->spritelst = NULL;
	d->inventory = 0;
	d->b_pistol = 0;
	d->b_shootgun = 0;
	d->b_nukegun = 0;
	d->b_handcard = 0;
	d->b_shoot = 0;
	d->b_action = 0;
	d->b_player_shooted = 0;
	d->b_player_spistol = 0;
	d->old_time = clock();
	d->old_step_time = clock();
	d->diff_time = 0;
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
		init_text_null(&d);
		if (parse(&d, av[1]))
			main_loop(&d);
		else
		{
			error_display(&d);
			exit_init(&d);
		}
	}
}
