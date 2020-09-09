/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:05:32 by memartin          #+#    #+#             */
/*   Updated: 2020/04/27 19:23:01 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int		check_format(char *line)
{
	while (is_whitespace(*line))
		line++;
	if (!ft_isdigit(*line) || ft_atoi(line) < 0 || ft_atoi(line) > 255)
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (0);
	line++;
	if (!ft_isdigit(*line) || ft_atoi(line) < 0 || ft_atoi(line) > 255)
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (0);
	line++;
	if (!ft_isdigit(*line) || ft_atoi(line) < 0 || ft_atoi(line) > 255)
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (is_whitespace(*line))
		line++;
	if (*line != '\0')
		return (0);
	return (1);
}

static int		get_color(char *line, t_rgb *rgb)
{
	while (is_whitespace(*line))
		line++;
	rgb->r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	rgb->g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	rgb->b = ft_atoi(line);
	rgb->rgb = rgb->r;
	rgb->rgb = (rgb->rgb << 8) + rgb->g;
	rgb->rgb = (rgb->rgb << 8) + rgb->b;
	return (1);
}

static void		choose_color(t_data *d, t_parse *p, char *line, int color)
{
	if (*line == 'F')
	{
		if (p->f_color)
		{
			p->error = 1;
			d->error.e_f_color = 1;
			return ;
		}
		d->f_color = color;
		p->f_color = 1;
	}
	if (*line == 'C')
	{
		if (p->c_color)
		{
			p->error = 1;
			d->error.e_c_color = 1;
			return ;
		}
		d->c_color = color;
		p->c_color = 1;
	}
}

void			parse_color(t_data *d, t_parse *p, char *line)
{
	t_rgb	rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	while (is_whitespace(*line))
		line++;
	if (!check_format(line + 2))
	{
		printf("bad format\n");
		p->error = 1;
		if (*line == 'F')
			d->error.e_f_color = 1;
		else if (*line == 'C')
			d->error.e_c_color = 1;
		return ;
	}
	get_color(line + 2, &rgb);
	choose_color(d, p, line, rgb.rgb);
}
