# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 20:44:31 by myunkim           #+#    #+#              #
#    Updated: 2022/09/01 21:07:09 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

DIR_OBJS = ./objs/

NAME = libgnl.a
SRCS = get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

all : $(NAME)

$(DIR_OBJS) :
	@mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : %.c
	@$(CC) $(CFLAGS) -I ./ -c $< -o $@

$(OBJS) : | $(DIR_OBJS)

$(NAME) : $(OBJS)
	@ar rc $@ $(OBJS)

clean :
	rm -rf $(DIR_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re