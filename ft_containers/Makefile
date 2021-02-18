NAME	=	test
SRCS	=	Test/test_list.cpp \
			Test/test_vector.cpp \
			Test/test_map.cpp \
			Test/test_stack.cpp \
			Test/test_queue.cpp \
			main.cpp
			
OBJS	=	$(SRCS:.cpp=.opp)
CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

%.opp	:	%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS) .tmp

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
