NAME = cub3D

NAME_BONUS = cub3d

SOURCES_DIR = ./srcs

BONUS_DIR = ./bonus

INCLUDES_DIR = ./includes

G3 =  -g3 -fsanitize=address

COMPIL = gcc

FLAG =

FLAG_MLX = -L./minilibx -lmlx -L/usr/include../lib -lXext -lX11 -lm -lbsd

HEADER = -I $(INCLUDES_DIR) -I/usr/include -I./minilibx

LIBFT = libft/libft.a

SRCS_NAME = main.c parse.c parse_texture.c parse_res.c parse_color.c parse_map.c parse_utils.c\
			parse_utils_lst.c main_loop.c raycast.c image.c events.c loop_manager.c move.c\
			exit_game.c files_utils.c texture.c sprite.c draw_sprite.c bitmap.c camera.c\
			parse_map_utils.c\

BONUS_NAME = main_bonus.c parse_bonus.c parse_texture_bonus.c parse_res_bonus.c\
			parse_color_bonus.c parse_map_bonus.c parse_utils_bonus.c\
			parse_utils_lst_bonus.c main_loop_bonus.c raycast_bonus.c image_bonus.c\
			events_bonus.c loop_manager_bonus.c move_bonus.c exit_game_bonus.c\
			files_utils_bonus.c texture_bonus.c sprite_bonus.c draw_sprite_bonus.c\
			bitmap_bonus.c camera_bonus.c parse_map_utils_bonus.c\
			hud_bonus.c\

SRCS = $(addprefix $(SOURCES_DIR)/,$(SRCS_NAME))

SRCS_BONUS = $(addprefix $(BONUS_DIR)/,$(BONUS_NAME))

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME):	$(LIBFT) $(OBJS)
	@$(COMPIL) $(FLAG) $(HEADER) $(OBJS) -L./libft -lft $(FLAG_MLX) -o $(NAME)

$(LIBFT):	
	@make -C ./libft re

%.o: %.c
	@$(COMPIL) $(FLAG) $(HEADER) -c $< -o $@

all:	$(NAME)

$(NAME_BONUS):	$(LIBFT) $(OBJS_BONUS)
	@$(COMPIL) $(FLAG) $(HEADER) $(OBJS_BONUS) -L./libft -lft $(FLAG_MLX) -o $(NAME)

bonus:	fclean $(NAME_BONUS)

clean :	
	@make -C ./libft clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean :	clean
		@make -C ./libft fclean 
		@rm -f ./$(NAME)
		@rm -f ./$(NAME_BONUS)

re:		fclean bonus

.PHONY:		all bonus clean fclean re
