/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:04:43 by memartin          #+#    #+#             */
/*   Updated: 2020/04/30 11:44:22 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		init_parse(t_parse *p)
{
	p->fd = 0;
	p->error = 0;
	p->screen_res = 0;
	p->no_t = 0;
	p->so_t = 0;
	p->we_t = 0;
	p->ea_t = 0;
	p->s_t = 0;
	p->m_ok = 0;
	p->f_color = 0;
	p->c_color = 0;
	p->player = 0;
}

static void		parse_line(t_data *d, t_parse *p, char *l)
{
	while (is_whitespace(l[p->i]))
		p->i++;
	if (l[p->i] == 'R' && is_whitespace(l[p->i + 1]))
		parse_res(d, p, l + p->i);
	else if (l[p->i] == 'N' && l[p->i + 1] == 'O' && is_whitespace(l[p->i + 2]))
		parse_no_texture(d, p, l + p->i);
	else if (l[p->i] == 'S' && l[p->i + 1] == 'O' && is_whitespace(l[p->i + 2]))
		parse_so_texture(d, p, l + p->i);
	else if (l[p->i] == 'W' && l[p->i + 1] == 'E' && is_whitespace(l[p->i + 2]))
		parse_we_texture(d, p, l + p->i);
	else if (l[p->i] == 'E' && l[p->i + 1] == 'A' && is_whitespace(l[p->i + 2]))
		parse_ea_texture(d, p, l + p->i);
	else if (l[p->i] == 'S' && is_whitespace(l[p->i + 1]))
		parse_sprite(d, p, l + p->i);
	else if ((l[p->i] == 'F' || l[p->i] == 'C') && is_whitespace(l[p->i + 1]))
		parse_color(d, p, l);
	else if (is_empty_line(l))
		return ;
	else if (is_map_line(l))
		parse_map(d, p, l);
	else
	{
		p->error = 1;
		d->error.e_file = 1;
	}
}

static int		is_parse_complete(t_data *d, t_parse *p)
{
	if (p->screen_res && p->no_t && p->so_t && p->we_t && p->ea_t && p->s_t
		&& p->m_ok && p->f_color && p->c_color)
		return (1);
	p->error = 1;
	d->error.e_missing = 1;
	return (0);
}

int				parse(t_data *d, char *path)
{
	t_parse	p;
	char	*line;

	init_parse(&p);
	p.fd = open(path, O_RDONLY);
	if (p.fd <= 0 || !is_valid_extension(path, ".cub"))
	{
		d->error.e_fd = 1;
		close(p.fd);
		return (0);
	}
	while (get_next_line(p.fd, &line))
	{
		p.i = 0;
		parse_line(d, &p, ft_strdup(line));
		if (line)
			free(line);
		if (p.error)
			break ;
	}
	close(p.fd);
	if (is_parse_complete(d, &p))
		return (1);
	return (0);
}
