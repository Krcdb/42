#include "../includes/cub3d.h"

static void			print_tab(char **tab)
{
	int		i = 0;

	printf("print tab\n");
	while (tab[i])
	{
		printf("line : %2d || {%s}\n", i, tab[i]);
		i++;
	}
}

static int		is_corner_valid(t_data *d, size_t x, size_t y)
{
	if (x == 0 && y == 0 &&
		((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
		(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
		return (0);
	else if (x == (d->map_x - 1) && y == 0 &&
		((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
		(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
		return (0);
	else if (x == 0 && y == (d->map_y - 1) &&
		((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
		(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);
	else if (x == (d->map_x - 1) && y == (d->map_y - 1) &&
		((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
		(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);
	return (1);
}

static int		is_border_valid(t_data *d, size_t x, size_t y)
{
	if (!is_corner_valid(d, x, y))
		return (0);
	else
		return (1);
	if (x == 0  && ((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
		(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1') ||
		(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
		return (0);
	else if (x == (d->map_x - 1)  && ((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
		(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1') ||
		(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);	
	else if (y == 0  && ((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
		(d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
		(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1')))
		return (0);	
	else if (y == (d->map_y - 1)  && ((d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
		(d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
		(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);
	return (1);
}

static int		is_valid_char(char c, t_data *d, t_parse *p, size_t x, size_t y)
{
	if (x == 0 || y == 0 || x == d->map_x - 1 || y == d->map_y - 1)
	{
		if (c != ' ' && c != '1')
			return (0);
		else if (c == ' ' && !is_border_valid(d, x, y))
				return (0);
		return (1);
	}
	else if (c == ' ' && ((d->map[y][x + 1] != ' ' && d->map[y][x + 1] != '1') ||
		(d->map[y][x - 1] != ' ' && d->map[y][x - 1] != '1') ||
		(d->map[y + 1][x] != ' ' && d->map[y + 1][x] != '1') ||
		(d->map[y - 1][x] != ' ' && d->map[y - 1][x] != '1')))
		return (0);
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && p->player)
		return (0);
	else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && !p->player)
		p->player = 1;
	return (1);
}
	
static void		is_map_valid(t_data *d, t_parse *p)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < d->map_y)
	{
		x = 0;
		while (x < d->map_x)
		{
			if (!is_valid_char(d->map[y][x], d, p, x, y))
			{
				printf("map error x : %ld || y : %ld\n", x, y);
				p->error = 1;
				d->error.e_map = 1;
				return ;
			}
			x++;
		}
		y++;
	}
}


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
	print_tab(d->map);
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
			d->error.e_file = 1;
			break ;
		}
		lstaddend(&mlst, newlst(line, ft_strlen(line)));
		if (line)
			free(line);
	}
	map_lst_to_tab(d, p, mlst);
	lstdel(&mlst);
	is_map_valid(d, p);
	if (p->player && !p->error)
	{
		p->m_ok = 1;
		printf("map ok\n");
	}
}
