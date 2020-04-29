/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 20:18:27 by memartin          #+#    #+#             */
/*   Updated: 2020/04/29 17:14:50 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <time.h>
# include <stdio.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define E_KEY 101
# define C_KEY 99
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define SHIFT_KEY 65505
# define SPACE_KEY 32
# define CTRL_KEY 65507
# define LEFT_KEY 65363
# define RIGHT_KEY 65361
# define ESC_KEY 65307

# define EXIT_PATH "./textures/exitwall.xpm"
# define SECRET_PATH "./textures/deadwall128.xpm"
# define DOOR_PATH "./textures/door128.xpm"
# define LOCKED_PATH "./textures/lockeddoor128.xpm"

# define DEAD_PATH "./textures/deadpig128.xpm"
# define PISTOL_DROP_PATH "./textures/pistoldrop.xpm"
# define SHOOT_DROP_PATH "./textures/shootdrop.xpm"
# define NUKE_DROP_PATH "./textures/nukedrop.xpm"
# define GLASS_PATH "./textures/glass128.xpm"
# define CARD_PATH "./textures/bluecard.xpm"

# define PISTOL_HUD_PATH "./textures/pistol_hud.xpm"
# define PISTOL1_HUD_PATH "./textures/pistol1.xpm"
# define PISTOL2_HUD_PATH "./textures/pistol2.xpm"
# define SHOOT_HUD_PATH "./textures/shootgun_hud.xpm"
# define NUKE_HUD_PATH "./textures/nukegun_hud.xpm"
# define HANDCARD_PATH "./textures/cardhand.xpm"

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
	char				type;

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

	t_texture		exit_t;
	t_texture		secret_t;
	t_texture		lock_t;
	t_texture		door_t;

	t_texture		mob_t;
	t_texture		deadmob_t;
	t_texture		pistoldrop_t;
	t_texture		shootdrop_t;
	t_texture		nukedrop_t;
	t_texture		glass_t;
	t_texture		card_t;

	t_hud			pistol_t;
	t_hud			pistol1_t;
	t_hud			pistol2_t;
	t_hud			shootgun_t;
	t_hud			nuke_t;
	t_hud			handcard_t;

	t_spritelist	*spritelst;
	t_spritelist	*spritedraw;
	double			*z_buffer;
	int				s_text_x;
	int				s_text_y;
	int				pxl_color;

	int				inventory;
	int				b_pistol;
	int				b_shootgun;
	int				b_nukegun;
	int				b_handcard;

	int				b_one;
	int				b_two;
	int				b_three;
	int				b_four;
	int				b_action;
	int				b_shoot;
	int				b_player_shooted;
	int				b_player_spistol;

	clock_t			old_time;
	clock_t			old_step_time;
	float			diff_time;
}					t_data;

typedef struct		s_parse
{
	int		error;
	int		i;
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
int					is_valid_map_char(char c);
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
t_texture			*get_texture(t_data *d, char c);
void				put_texture_on_img(t_data *d, int x, t_texture *t);
void				sprite_hit(t_data*d, int x);
void				del_all_sprite(t_spritelist **hlst);
void				print_sprite(t_spritelist *hlst);
void				draw_sprite(t_data *d);
void				draw_hud(t_data *d, t_hud *t);
void				sort_sprite(t_spritelist **spritelst);
void				exit_init(t_data *d);
void				bitmap(t_data *d);
int					init_hud_textures(t_data *d);
int					init_wall_text(t_data *d);
int					init_sprite_text(t_data *d);
int					is_wall(char c);
int					is_sprite(char c);
int					is_walk(char c);
t_hud				*get_hud(t_data *d);
void				action_detection(t_data *d);
void				player_shoot(t_data *d);
float				get_diff_time(clock_t old);
void				update_bool_time(t_data *d);
void				draw_glass(t_data *d, t_spritelist *sp);
void				put_glass_line_to_img(t_data *d, int x, t_texture *t);
void				after_move(t_data *d);
void				step_sound(t_data *d);

#endif
