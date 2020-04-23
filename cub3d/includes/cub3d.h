/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 20:18:27 by memartin          #+#    #+#             */
/*   Updated: 2020/04/23 20:21:43 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# define NO_C 0255000000
# define SO_C 0000000255
# define WE_C  0255125125
# define EA_C  0000255000
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define SHIFT_KEY 65505
# define LEFT_KEY 65363
# define RIGHT_KEY 65361
# define ESC_KEY 65307
# define TEXT_SIZE 64

typedef struct		s_rgb
{
	int		r;
	int		g;
	int		b;
	int		rgb;
}					t_rgb;

typedef struct		s_maplist
{
	char				*content;
	size_t				content_size;
	struct s_maplist	*next;
}					t_maplist;

typedef struct		s_spritelist
{
	int					map_x;
	int					map_y;
	int					nb_sprite;
	double				dist;

	int					screen_x;
	int					height;
	int					width;
	double				transform_x;
	double				transform_y;
	int					draw_start_y;
	int					draw_end_y;
	int					draw_start_x;
	int					draw_end_x;
	struct s_spritelist	*next;
}					t_spritelist;

typedef struct		s_hud
{
	char	*data;
	void	*img;
	int		draw_s_x;
	int		draw_e_x;
	int		draw_s_y;
	int		draw_e_y;
	int		width;
	int		height;
	int		bpp;
	int		s_l;
	int		endian;
}					t_hud;

typedef struct		s_texture
{
	char	*data;
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		s_l;
	int		endian;
}					t_texture;

typedef struct		s_error
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
}					t_error;

typedef struct		s_data
{
	t_error			error;
	int				save;
	int				screen_x;
	int				screen_y;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*sprite_path;
	char			**map;
	size_t			map_x;
	size_t			map_y;
	int				f_color;
	int				c_color;
	int				player_x;
	int				player_y;
	char			p_orientation;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				exit_game;

	double			plane_x;
	double			plane_y;
	double			dir_x;
	double			dir_y;
	double			pos_x;
	double			pos_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_x;
	double			delta_y;
	double			side_dist_x;
	double			side_dist_y;
	double			wall_dist;

	int				step_x;
	int				step_y;
	int				ray_x;
	int				ray_y;
	int				hit;
	int				side;
	int				text_x;
	int				text_y;
	double			text_pos;
	double			wall_x;
	double			step;

	int				line_height;
	int				draw_start;
	int				draw_end;

	int				bpp;
	int				s_l;
	int				endian;

	int				strafe_left;
	int				strafe_right;
	int				move_forward;
	int				move_backward;
	int				rotate_left;
	int				rotate_right;
	int				sprint;
	double			speed;
	double			rotation;

	t_texture		north_t;
	t_texture		south_t;
	t_texture		east_t;
	t_texture		west_t;
	t_texture		sprite_t;
	t_hud			sgun_t;

	t_spritelist	*spritelst;
	t_spritelist	*spritedraw;
	double			*z_buffer;
	int				s_text_x;
	int				s_text_y;
	int				pxl_color;
}					t_data;

typedef struct		s_parse
{
	int		error;
	int		screen_res;
	int		no_t;
	int		so_t;
	int		we_t;
	int		ea_t;
	int		s_t;
	int		m_found;
	int		m_ok;
	int		f_color;
	int		c_color;
	int		fd;
	int		player;
	char	c;
}					t_parse;

int					parse(t_data *d, char *path);
void				parse_res(t_data *d, t_parse *p, char *line);
void				parse_color(t_data *d, t_parse *p, char *line);
void				parse_no_texture(t_data *d, t_parse *p, char *line);
void				parse_so_texture(t_data *d, t_parse *p, char *line);
void				parse_we_texture(t_data *d, t_parse *p, char *line);
void				parse_ea_texture(t_data *d, t_parse *p, char *line);
void				parse_sprite(t_data *d, t_parse *p, char *line);
void				parse_map(t_data *d, t_parse *p, char *line);
void				set_player_pos(t_data *d, t_parse *p, int x, int y);
void				set_parse_map_error(t_data *d, t_parse *p);
int					is_corner_valid(t_data *d, size_t x, size_t y);
int					is_empty_line(char *line);
int					is_map_line(char *line);
int					is_map_char(char c);
int					is_whitespace(char c);
int					is_filepath_valid(const char *path);
int					is_valid_extension(const char *path, const char *ext);
t_maplist			*newlst(const char *content, size_t content_size);
void				lstaddend(t_maplist **hlst, t_maplist *nlst);
void				lstdel(t_maplist **hlst);
size_t				get_longest_line(t_maplist *hlst);
size_t				get_nb_line(t_maplist *hlst);
void				print_lst(t_maplist *mlst);
char				*cpy_lst_to_map(char *dst, const char *src);
void				main_loop(t_data *d);
void				raycast(t_data *d);
void				put_line_to_img(t_data *d, int x);
int					event_key_pressed(int key, void *param);
int					event_key_released(int key, void *param);
int					loop_manager(void *param);
int					exit_game(void *param);
void				key_manager(t_data *d);
void				strafe_left(t_data *d);
void				strafe_right(t_data *d);
void				move_forward(t_data *d);
void				move_backward(t_data *d);
void				init_pos_camera(t_data *d);
void				rotate_left(t_data *d);
void				rotate_right(t_data *d);
void				print_tab(char **tab);
t_texture			*get_texture(t_data *d);
void				put_texture_on_img(t_data *d, int x, t_texture *t);
void				sprite_hit(t_data*d);
void				del_all_sprite(t_spritelist **hlst);
void				print_sprite(t_spritelist *hlst);
void				draw_sprite(t_data *d);
void				sort_sprite(t_spritelist **spritelst);
void				exit_init(t_data *d);
void				bitmap(t_data *d);

#endif
