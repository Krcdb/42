NAME = cub3D

SOURCES_DIR = ./srcs

OBJECTS_DIR = ./obj

INCLUDES_DIR = ./includes

G3 =  -g3 -fsanitize=address

COMPIL = gcc

FLAG = 

FLAG_MLX = -L./minilibx -lmlx -L/usr/include../lib -lXext -lX11 -lm -lbsd

HEADER = -I $(INCLUDES_DIR) -I/usr/include -I./minilibx

LIBFT = libft/libft.a

SRCS_NAME = main.c parse.c parse_texture.c parse_res_color.c parse_map.c parse_utils.c\
			parse_utils_lst.c main_loop.c raycast.c image.c events.c loop_manager.c move.c\
			exit_game.c files_utils.c texture.c\

SRCS = $(addprefix $(SOURCES_DIR)/,$(SRCS_NAME))

OBJS = $(SRCS:.c=.o)

$(NAME):	$(LIBFT) $(OBJS)
	@$(COMPIL) $(FLAG) $(HEADER) $(OBJS) -L./libft -lft $(FLAG_MLX) -o $(NAME)

$(LIBFT):	
	@make -C ./libft re

%.o: %.c
	@$(COMPIL) $(FLAG) $(HEADER) -c $< -o $@

all:	$(NAME)

bonus:	$(NAME)

clean :	
	@make -C ./libft clean
	@rm -f $(OBJS)

fclean :	clean
		@make -C ./libft fclean 
		@rm -f ./$(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
