# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 16:32:39 by mmartine          #+#    #+#              #
#    Updated: 2018/05/24 15:47:29 by mmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_FILE = ft_conv.c\
		   ft_conv_c.c\
		   ft_conv_s.c\
		   ft_conv_oux.c\
		   ft_conv_di.c\
		   ft_conv_p.c\
		   ft_conv_majc.c\
		   ft_conv_uni.c\
		   ft_data_init.c\
		   ft_data_reset.c\
		   ft_imtoa.c\
		   ft_intsize.c\
		   ft_parse.c\
		   ft_print_buff.c\
		   ft_putstr.c\
		   ft_putchar_buff.c\
		   ft_put_conv.c\
		   ft_printf.c\
		   ft_atoi.c\
		   ft_strdel.c\
		   ft_strlen.c\
		   ft_strchr.c\
		   ft_strjoinfree.c\
		   ft_strnew.c\
		   ft_isdigit.c\
		   ft_bzero.c\
		   ft_utoa_b.c\
		   ft_strdup.c\
		   ft_intsize_b.c\
		   ft_toupper.c\


OBJ = $(SRC_FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
