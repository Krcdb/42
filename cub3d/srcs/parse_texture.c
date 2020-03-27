#include "../includes/cub3d.h"

void			parse_no_texture(t_data *d, t_parse *p, char *line)
{
	line += 3;
	if (p->no_t || ft_strcmp(line, "./textures/north_texture"))
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
	line += 3;
	if (p->so_t || ft_strcmp(line, "./textures/south_texture"))
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
	line += 3;
	if (p->we_t || ft_strcmp(line, "./textures/west_texture"))
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
	line += 3;
	if (p->ea_t || ft_strcmp(line, "./textures/east_texture"))
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
	line += 2;
	if (p->s_t || ft_strcmp(line, "./textures/sprite_texture"))
	{
		p->error = 1;
		d->error.e_s_t = 1;
		return ;
	}
	d->sprite_path = ft_strdup(line);
	p->s_t = 1;
}
