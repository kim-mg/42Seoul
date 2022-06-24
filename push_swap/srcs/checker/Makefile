# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 17:18:24 by myunkim           #+#    #+#              #
#    Updated: 2022/02/12 00:48:33 by myunkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

DIR_HEADERS	= ./includes/
DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/

NAME		= checker
SRCS		= checker.c \
			get_next_line.c \
			gnl_utils.c \
			initialize.c \
			operations.c \
			utils.c

OBJS		= $(SRCS:%.c=$(DIR_OBJS)%.o)

all : $(NAME)

debug : CFLAGS += -g3 -fsanitize=address
debug : all

$(DIR_OBJS) :
	mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.c
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(OBJS) : | $(DIR_OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(DIR_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re