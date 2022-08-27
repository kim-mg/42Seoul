# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:57:46 by myunkim           #+#    #+#              #
#    Updated: 2022/08/27 16:24:34 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OS = $(shell uname)

ifeq ($(OS), Darwin)
	MLX = ./mlx
	LINK = -L $(MLX) -lmlx -framework OpenGL -framework Appkit
else
	MLX = ./minilibx-linux
	LINK = -L $(MLX) -lmlx -lm -lXext -lX11
endif

DIR_HEADERS = ./includes/
DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
DIR = ./

DIR_LIB = ./lib/
LFLAGS = -L $(DIR_LIB) -lft -lgnl -lftprintf

NAME = cub3D
SRCS = main.c

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

all : $(NAME)

debug += CC CFLAGS -g3 fsanitize=address
debug : all

$(DIR_OBJS) :
	@$(MAKE) -C $(DIR_LIB) MAKEFLAGS=
	mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.c
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(OBJS) : | $(DIR_OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLGAS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME) $(LFLAGS) $(LINK)

clean :
	@make clean -C $(DIR_LIB)
	rm -rf $(DIR_OBJS)

fclean : clean
	@make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
