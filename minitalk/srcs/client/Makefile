# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 22:48:54 by myunkim           #+#    #+#              #
#    Updated: 2022/03/06 01:09:46 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
DIR = ./

DIR_LIB = ../libft/
LFLAGS = -lft -L$(DIR_LIB)

NAME = client
SRCS = client.c

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

DIR_BNS_SRCS = ./b_srcs/
BNS_SRCS = client_bonus.c

BNS_OBJS = $(BNS_SRCS:%.c=$(DIR_OBJS)%.o)

ifdef BONUS
	CUR_OBJS = $(BNS_OBJS)
	CUR_SRCS = $(DIR_BNS_SRCS)
else
	CUR_OBJS = $(OBJS)
	CUR_SRCS = $(DIR_SRCS)
endif

all : $(NAME)

debug : CFLAGS += -g3 fsanitize=address
debug : all

$(DIR_OBJS) :
	@mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : $(CUR_SRCS)%.c
	@printf "\033[2K\r\033[33m Compiling $< \033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(CUR_OBJS) : | $(DIR_OBJS)

$(NAME) : $(CUR_OBJS)
	@$(CC) $(CFLAGS) -I. $(CUR_OBJS) -o $(NAME) $(LFLAGS)
	@printf "\033[2K\r\033[32m >> '$(NAME)' program file was created.\033[0m\n"

bonus :
	@make -s BONUS=1 all

clean :
	@rm -rf $(DIR_OBJS)
	@printf "\033[2K\r\033[31m >> '"$(NAME)"' objects files has been deleted.\033[0m\n"

fclean : clean
	@rm -rf $(NAME)
	@printf "\033[2K\r\033[31m >> '$(NAME)' has been deleted.\033[0m\n"

re : fclean all

.PHONY : all bonus clean fclean re