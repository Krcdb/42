/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:54:48 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:13:04 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		free_textures(t_data *d)
{
	if (d->north_t.img)
		mlx_destroy_image(d->mlx_ptr, d->north_t.img);
	if (d->south_t.img)
		mlx_destroy_image(d->mlx_ptr, d->south_t.img);
	if (d->west_t.img)
		mlx_destroy_image(d->mlx_ptr, d->west_t.img);
	if (d->east_t.img)
		mlx_destroy_image(d->mlx_ptr, d->east_t.img);
	if (d->sprite_t.img)
		mlx_destroy_image(d->mlx_ptr, d->sprite_t.img);
}

void			del_all_sprite(t_spritelist **hlst)
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

void			exit_init(t_data *d)
{
	int		i;

	i = 0;
	if (d->map)
	{
		while (d->map[i])
		{
			if (d->map[i])
				free(d->map[i]);
			i++;
		}
		free(d->map);
	}
	if (d->north_path)
		free(d->north_path);
	if (d->south_path)
		free(d->south_path);
	if (d->east_path)
		free(d->east_path);
	if (d->west_path)
		free(d->west_path);
	if (d->sprite_path)
		free(d->sprite_path);
}

int				exit_game(void *param)
{
	t_data *d;

	d = (t_data *)param;
	if (d->win_ptr != NULL)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	if (d->img_ptr)
		mlx_destroy_image(d->mlx_ptr, d->img_ptr);
	exit_init(d);
	free_textures(d);
	if (d->z_buffer)
		free(d->z_buffer);
	del_all_sprite(&d->spritelst);
	ft_printf("exit game\n");
	exit(0);
}
