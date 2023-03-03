# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memartin <memartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 11:52:41 by memartin          #+#    #+#              #
#    Updated: 2020/12/07 11:19:37 by memartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix $(FOLDER), \
			philo_two.c \
			philosophers.c \
			init.c \
			utils.c \
			exit.c \
			display.c \
			supervisor.c \
			time.c \
			)

OBJS	= $(SRCS:.c=.o)

FOLDER	= srcs/

INCS	= includes/

NAME	= philo_two

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -pthread

ifeq ($(DEBUG), true)
	CFLAGS += -g -fsanitize=address
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@ 

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re