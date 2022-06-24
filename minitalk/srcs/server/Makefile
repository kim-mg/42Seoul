# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 22:47:30 by myunkim           #+#    #+#              #
#    Updated: 2022/03/06 01:07:27 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIR_HEADERS = ./includes/
DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
DIR = ./

DIR_LIB = ../libft/
LFLAGS = -lft -L$(DIR_LIB)

NAME = server
SRCS = chat.c \
		server.c

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

DIR_BNS_SRCS = ./b_srcs/
BNS_SRCS = chat_bonus.c \
			server_bonus.c

BNS_OBJS = $(BNS_SRCS:%.c=$(DIR_OBJS)%.o)

ifdef BONUS
	CUR_OBJS = $(BNS_OBJS)
	CUR_SRCS = $(DIR_BNS_SRCS)
else
	CUR_OBJS = $(OBJS)
	CUR_SRCS = $(DIR_SRCS)
endif

all : $(NAME)

debug : CC CFLAGS -g3 fsanitize=address
debug : all

$(DIR_OBJS) :
	@mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : $(CUR_SRCS)%.c
	@printf "\033[2K\r\033[33m Compiling $< \e[0m"
	@$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(CUR_OBJS) : | $(DIR_OBJS)

$(NAME) : $(CUR_OBJS)
	@$(CC) $(CFLAGS) -I $(DIR_HEADERS) $(CUR_OBJS) -o $(NAME) $(LFLAGS)
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