# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 23:25:25 by myunkim           #+#    #+#              #
#    Updated: 2022/06/20 20:28:12 by hyno             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

OS = $(shell uname)

ifeq ($(OS), Darwin)
	RL_PATH = $(shell brew --prefix readline)/
else
	RL_PATH = /usr/local/opt/readline/
endif

DIR_HEADERS = ./includes/
DIR_SRCS = srcs/
DIR_OBJS = ./objs/
DIR = ./

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

RL_HEADER = $(RL_PATH)include/
RL_DIR = $(RL_PATH)lib/
LINK = -L $(LIBFT_DIR) -lft -L $(RL_DIR) -lreadline

NAME = minishell
DIR_BUILTIN = builtin/
DIR_ERROR = error/
DIR_EXEC = exec/
DIR_PARSE = parse/
DIR_RUNTIME = runtime/
DIR_UTILS = utils/
SRCS_BUILTIN	=	cd.c				\
					echo.c				\
					env.c				\
					exit.c				\
					export.c			\
					pwd.c				\
					unset.c			
SRCS_EXEC		=	command.c			\
					command_path.c		\
					pipe.c				\
					redirection.c		\
					redirection_exec.c
SRCS_PARSE		=	envval.c			\
					get_minimum_node.c	\
					parse_error.c 		\
					parsing.c			\
					replace_string.c	\
					token.c
SRCS_RUNTIME	=	execute.c			\
					execute_cmd.c		\
					execute_exit.c		\
					execute_waitpid.c	\
					signal.c			\
					termios.c			\
					error.c
SRCS_UTILS		=	free_struct.c		\
					utils.c				\
					util_cast.c			\
					util_list.c			\
					util_string.c
SRCS	=	main.c		\
			$(SRCS_BUILTIN)	\
			$(SRCS_ERROR)	\
			$(SRCS_EXEC)	\
			$(SRCS_PARSE)	\
			$(SRCS_RUNTIME)	\
			$(SRCS_UTILS)

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))
VPATH = $(shell ls -R)

all : $(NAME)

debug : CC CFLAGS -g3 fsanitize=address
debug : all

$(DIR_OBJS) :
	mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : %.c
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) -I $(RL_HEADER) -c $< -o $@

$(OBJS) : | $(DIR_OBJS)

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_DIR) MAKEFLAGS=

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME) $(LINK) -I $(RL_HEADER)

clean :
	$(MAKE) clean -C $(LIBFT_DIR) MAKEFLAGS=
	$(RM) $(DIR_OBJS)
	$(RM) .heredoc

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR) MAKEFLAGS=
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re