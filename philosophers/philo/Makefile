# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 22:01:39 by myunkim           #+#    #+#              #
#    Updated: 2022/05/20 00:40:04 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIR_HEADERS = ./includes/
DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
DIR = ./

DIR_LIB = 
LFLAGS = -lpthread

DEBUG = -g

NAME = philo
SRCS = philo.c \
		elapse.c \
		error.c \
		print_line.c \
		state.c \
		utils.c \
		checker.c

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

all : $(NAME)

$(DIR_OBJS) :
	mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.c
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(OBJS) : | $(DIR_OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLGAS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME) $(LFLAGS) $(LINK)

debug : DEBUG += debug
debug : all

clean :
	rm -rf $(DIR_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re debug