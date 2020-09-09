# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 14:14:16 by memartin          #+#    #+#              #
#    Updated: 2020/07/29 15:10:54 by memartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix $(FOLDER), \
			philo_one.c \
			utils.c \
			atoi_boi.c \
			ltoa.c \
			)

OBJS	= $(SRCS:.c=.o)

FOLDER	= srcs/

INCS	= includes/

NAME	= philo_one

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

TFLAG	= -lpthread

ifeq ($(DEBUG), true)
	CFLAGS += -g -fsanitize=address
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(TFLAG) $(OBJS) -o $(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@ 

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
