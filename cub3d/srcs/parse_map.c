#include "../includes/cub3d.h"

void		parse_map(t_data *d, t_parse *p, char *line)
{
	t_maplist	*mlst;

	mlst = newlst(line, ft_strlen(line));
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
	printf("longest : %ld\n", get_longest_line(mlst));
	lstdel(&mlst);
	print_lst(mlst);
}
