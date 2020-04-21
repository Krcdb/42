#include "../includes/cub3d.h"

static int		check_error(char *line)
{
	if (!ft_isdigit(*line))
		return (1);
	else if (ft_atoi(line) < 0 || ft_atoi(line) > 255)
		return (1);
	else
		return (0);
}

static int		convert_color_in_int(char *line)
{
	int		res;

	res = 0;
	if (check_error(line))
		return (-1);
	res += ft_atoi(line) * 1000000;
	line += ft_intsize(ft_atoi(line));
	if (*line != ',')
		return (-1);
	line++;
	if (check_error(line))
		return (-1);
	res += ft_atoi(line) * 1000;
	line += ft_intsize(ft_atoi(line));
	if (*line != ',')
		return (-1);
	line++;
	if (check_error(line))
		return (-1);
	res += ft_atoi(line);
	if (*(line + ft_intsize(ft_atoi(line))) != '\0')
		return (-1);
	return (res);
}

void			parse_color(t_data *d, t_parse *p, char *line)
{
	int res;
	
	res = convert_color_in_int(line + 2);
	if (*line == 'F')
	{
		if (res == -1 || p->f_color)
		{
			p->error = 1;
			d->error.e_f_color = 1;
			return ;
		}
		d->f_color = res;
		p->f_color = 1;
	}
	if (*line == 'C')
	{
		if (res == -1 || p->c_color)
		{
			p->error = 1;
			d->error.e_c_color = 1;
			return ;
		}
		d->c_color = res;
		p->c_color = 1;
	}
	return ;
}

static void		set_error_res(t_data *d, t_parse *p)
{
	p->error = 1;
	d->error.e_screen_res = 1;
}

void			parse_res(t_data *d, t_parse *p, char *line)
{
	line += 2;
	if (!ft_isdigit(*line))
	{
		set_error_res(d, p);
		return ;
	}
	d->screen_x = ft_atoi(line);
	line += ft_intsize(d->screen_x);
	if (*line != ' ')
	{
		set_error_res(d, p);
		return ;
	}
	line++;
	if (!ft_isdigit(*line))
	{
		set_error_res(d, p);
		return ;
	}
	d->screen_y = ft_atoi(line);
	line += ft_intsize(d->screen_y);
	if (d->screen_x > 0 && d->screen_y > 0 && !p->screen_res && !*line)
		p->screen_res = 1;
	else
		set_error_res(d, p);
}
