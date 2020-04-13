#ifndef _CUB3D_H_
# define _CUB3D_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# define NO_C 0255000000
# define SO_C 0000000255
# define W_C  0255125125
# define E_C  0125125255

typedef struct		s_maplist
{
	char				*content;
	size_t				content_size;
	struct s_maplist	*next;
}					t_maplist;

typedef struct s_error
{
	int	e_screen_res;
	int	e_no_t;
	int	e_so_t;
	int	e_we_t;
	int	e_ea_t;
	int	e_s_t;
	int	e_f_color;
	int	e_c_color;
	int	e_fd;
	int	e_file;
	int	e_map;
	int	e_memory;
}				t_error;


typedef struct	s_data
{
	t_error	error;
	int     screen_x;
	int     screen_y;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*sprite_path;
	char    **map;
	size_t	map_x;
	size_t	map_y;
	int		f_color;
	int		c_color;
	int		player_x;
	int		player_y;
	char	p_orientation;
	void	*mlx_ptr;
	void	*win_ptr;

	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_dist;

	int		step_x;
	int		step_y;
	int		ray_x;
	int		ray_y;
	int		hit;
	int		side;

	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_data;
 

typedef struct	s_parse
{
	int error;
	int	screen_res;
	int	no_t;
	int	so_t;
	int	we_t;
	int	ea_t;
	int	s_t;
	int	m_found;
	int	m_ok;
	int	f_color;
	int	c_color;
	int fd;
	int	player;
}				t_parse;

int			parse(t_data *d, char *path);
void		parse_res(t_data *d, t_parse *p, char *line);
void		parse_color(t_data *d, t_parse *p, char *line);
void		parse_no_texture(t_data *d, t_parse *p, char *line);
void		parse_so_texture(t_data *d, t_parse *p, char *line);
void		parse_we_texture(t_data *d, t_parse *p, char *line);
void		parse_ea_texture(t_data *d, t_parse *p, char *line);
void		parse_sprite(t_data *d, t_parse *p, char *line);
void		parse_map(t_data *d, t_parse *p, char *line);
int			is_empty_line(char *line);
int			is_map_line(char *line);
int			is_map_char(char c);
t_maplist	*newlst(const char *content, size_t content_size);
void		lstaddend(t_maplist **hlst, t_maplist *nlst);
void		lstdel(t_maplist **hlst);
size_t		get_longest_line(t_maplist *hlst);
size_t		get_nb_line(t_maplist *hlst);
void		print_lst(t_maplist *mlst);
char		*cpy_lst_to_map(char *dst, const char *src);
void		make_window(t_data *d);
void		raycast(t_data *d);

#endif
