/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:33:55 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:14:23 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			parse_no_texture(t_data *d, t_parse *p, char *line)
{
	int		l;

	line += 3;
	while (is_whitespace(*line))
		line++;
	l = ft_strlen(line);
	if (p->no_t || !is_filepath_valid(line) ||
		!is_valid_extension(line, ".xpm"))
	{
		p->error = 1;
		d->error.e_no_t = 1;
		return ;
	}
	d->north_path = ft_strdup(line);
	p->no_t = 1;
}

void			parse_so_texture(t_data *d, t_parse *p, char *line)
{
	int		l;

	line += 3;
	while (is_whitespace(*line))
		line++;
	l = ft_strlen(line);
	if (p->so_t || !is_filepath_valid(line) ||
		!is_valid_extension(line, ".xpm"))
	{
		p->error = 1;
		d->error.e_so_t = 1;
		return ;
	}
	d->south_path = ft_strdup(line);
	p->so_t = 1;
}

void			parse_we_texture(t_data *d, t_parse *p, char *line)
{
	int		l;

	line += 3;
	while (is_whitespace(*line))
		line++;
	l = ft_strlen(line);
	if (p->we_t || !is_filepath_valid(line) ||
		!is_valid_extension(line, ".xpm"))
	{
		p->error = 1;
		d->error.e_we_t = 1;
		return ;
	}
	d->west_path = ft_strdup(line);
	p->we_t = 1;
}

void			parse_ea_texture(t_data *d, t_parse *p, char *line)
{
	int		l;

	line += 3;
	while (is_whitespace(*line))
		line++;
	l = ft_strlen(line);
	if (p->ea_t || !is_filepath_valid(line) ||
		!is_valid_extension(line, ".xpm"))
	{
		p->error = 1;
		d->error.e_ea_t = 1;
		return ;
	}
	d->east_path = ft_strdup(line);
	p->ea_t = 1;
}

void			parse_sprite(t_data *d, t_parse *p, char *line)
{
	int		l;

	line += 2;
	while (is_whitespace(*line))
		line++;
	l = ft_strlen(line);
	if (p->s_t || !is_filepath_valid(line) ||
		!is_valid_extension(line, ".xpm"))
	{
		p->error = 1;
		d->error.e_s_t = 1;
		return ;
	}
	d->sprite_path = ft_strdup(line);
	p->s_t = 1;
}
