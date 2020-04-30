/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:31:55 by memartin          #+#    #+#             */
/*   Updated: 2020/04/30 11:24:57 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		map_lst_to_tab(t_data *d, t_parse *p, t_maplist *mlst)
{
	size_t		i;

	i = 0;
	d->map_x = get_longest_line(mlst);
	d->map_y = get_nb_line(mlst);
	if (!(d->map = (char**)malloc(sizeof(char*) * (d->map_y + 1))))
	{
		d->error.e_memory = 1;
		p->error = 1;
		return ;
	}
	while (i < d->map_y)
	{
		d->map[i] = ft_strallocset(' ', d->map_x);
		if (d->map[i] == NULL)
		{
			d->error.e_memory = 1;
			p->error = 1;
			return ;
		}
		d->map[i] = cpy_lst_to_map(d->map[i], mlst->content);
		i++;
		mlst = mlst->next;
	}
	d->map[i] = 0;
}

static void		convert_and_check(t_data *d, t_parse *p, t_maplist *mlst)
{
	map_lst_to_tab(d, p, mlst);
	if (d->map_y > 2 && d->map_x > 2)
	{
		is_map_valid(d, p);
		set_parse_map_error(d, p);
	}
	else
	{
		p->error = 1;
		d->error.e_map = 1;
	}
}

void			parse_map(t_data *d, t_parse *p, char *line)
{
	t_maplist	*mlst;

	mlst = newlst(line, ft_strlen(line));
	if (line)
		free(line);
	while (get_next_line(p->fd, &line))
	{
		if (is_empty_line(line) || !is_map_line(line))
		{
			p->error = 1;
			d->error.e_map = 1;
			if (line)
				free(line);
			break ;
		}
		lstaddend(&mlst, newlst(line, ft_strlen(line)));
		if (line)
			free(line);
	}
	if (!p->error)
		convert_and_check(d, p, mlst);
	lstdel(&mlst);
}
