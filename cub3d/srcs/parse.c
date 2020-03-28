#include "../includes/cub3d.h"

static void	init_parse(t_parse *p)
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

static void		parse_line(t_data *d, t_parse *p, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_res(d, p, line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		parse_no_texture(d, p, line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		parse_so_texture(d, p, line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		parse_we_texture(d, p, line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		parse_ea_texture(d, p, line);
	else if (line[0] == 'S' && line[1] == ' ')
		parse_sprite(d, p, line);
	else if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		parse_color(d, p, line);
	else if (is_empty_line(line))
		return ;
	else if (is_map_line(line))
		parse_map(d, p, line);
	else
	{
		p->error = 1;
		d->error.e_file = 1;
	}
}

void		parse(t_data *d, char *path)
{
	t_parse	p;
	char	*line;

	init_parse(&p);
	p.fd = open(path, O_RDONLY);
	if (p.fd <= 0)
	{
		d->error.e_fd = 1;
		return ;
	}
	while (get_next_line(p.fd, &line))
	{
		parse_line(d, &p, line);
		if (line)
			free(line);
		if (p.error)
			break ;
	}
	close(p.fd);
}
