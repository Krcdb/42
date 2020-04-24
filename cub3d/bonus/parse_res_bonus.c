/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:32:48 by memartin          #+#    #+#             */
/*   Updated: 2020/04/24 13:44:38 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		set_error_res(t_data *d, t_parse *p)
{
	p->error = 1;
	d->error.e_screen_res = 1;
}

static int		check_format(char *line)
{
	while (is_whitespace(*line))
		line++;
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (!is_whitespace(*line))
		return (0);
	while (is_whitespace(*line))
		line++;
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (is_whitespace(*line))
		line++;
	if (*line != '\0')
		return (0);
	return (1);
}

void			parse_res(t_data *d, t_parse *p, char *line)
{
	line += 2;
	if (!check_format(line))
	{
		set_error_res(d, p);
		return ;
	}
	while (is_whitespace(*line))
		line++;
	d->screen_x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (is_whitespace(*line))
		line++;
	d->screen_y = ft_atoi(line);
	if (d->screen_x > 0 && d->screen_y > 0 && !p->screen_res)
		p->screen_res = 1;
	else
		set_error_res(d, p);
}
