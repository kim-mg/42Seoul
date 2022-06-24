# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 14:53:52 by myunkim           #+#    #+#              #
#    Updated: 2022/02/11 15:05:35 by myunkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

DIR_HEADERS = ./includes/
DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/

NAME		= push_swap
SRCS		= clean.c \
		  initialize.c \
		  instr_exec.c \
		  operations.c \
		  pivot.c \
		  push_swap.c \
		  solution_utils.c \
		  solution.c \
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
