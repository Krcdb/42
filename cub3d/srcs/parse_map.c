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

static void		map_lst_to_tab(t_data *d, t_maplist *mlst, size_t x, size_t y)
{
	size_t		i;

	i = 0;
	if (!(d->map = (char**)malloc(sizeof(char*) * (y + 1))))
		return ;
	while (i < y)
	{
		d->map[i] = ft_strallocset(' ', x);
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
	print_lst(mlst);
	map_lst_to_tab(d, mlst, get_longest_line(mlst), get_nb_line(mlst));
	lstdel(&mlst);
	print_lst(mlst);
}
