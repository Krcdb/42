/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:02:40 by user42            #+#    #+#             */
/*   Updated: 2020/05/19 14:00:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct 	s_zone
{
	int		width;
	int		height;
	char	c;
}				t_zone;

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			error_output(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(1, str, i);
	return (1);
}

int			get_zone(FILE *fp, t_zone *zone)
{
	int		ret;

	ret = 0;
	ret = fscanf(fp, "%d %d %c", &zone->width, &zone->height, &zone->c);
	if (ret != 3)
		return (0);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (0);
	return (1);
}

void		print_draw(char *draw, t_zone zone)
{
	int		i;
	int		j;

	j = 0;
	while (j < zone.height)
	{
		i = 0;
		while (i < zone.width)
		{
			write(1, &draw[i + j * zone.height], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}


char			*set_draw(t_zone zone)
{
	int		i;
	char	*draw;

	i = 0;
	if (!(draw =(char*)malloc(sizeof(char) * (zone.width * zone.height + 1))))
		return (NULL);
	while (i < zone.width * zone.height)
		draw[i++] = zone.c;
	draw[i] = '\0';
	return (draw);
}

int			main(int ac, char **av)
{
	FILE	*fp;
	t_zone	zone;
	char	*draw;

	zone.width = 0;
	zone.height = 0;
	zone.c = 0;
	if (ac != 2)
		return (error_output("Error: argument\n"));
	fp = fopen(av[1], "r");
	if (fp == NULL || !get_zone(fp, &zone))
		return (error_output("Error: file error\n"));
	draw = set_draw(zone);
	if (draw == NULL)
		return (error_output("Error: memory error\n"));
	print_draw(draw, zone);
	return (0);
}
