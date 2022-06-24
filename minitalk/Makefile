# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 23:08:55 by myunkim           #+#    #+#              #
#    Updated: 2022/03/07 16:45:29 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

MFLAGS = -s

SRCS = ./srcs
DIR = ./
DEBUG = 
BONUS =

CLIENT = client
SERVER = server
LIBFT = libft

all : $(LIBFT) $(CLIENT) $(SERVER)

debug : DEBUG += debug
debug : all

bonus : BONUS += bonus
bonus : all

$(LIBFT) :
	@$(MAKE) $(MFLAGS) $(DEBUG) -C $(SRCS)/$(LIBFT) MAKEFLAGS=

$(CLIENT) :
	@$(MAKE) $(MFLAGS) $(DEBUG) -C $(SRCS)/$(CLIENT) $(BONUS) MAKEFLAGS=
	@cp -rf $(SRCS)/$(CLIENT)/$(CLIENT) $(DIR)$(CLIENT)

$(SERVER) :
	@$(MAKE) $(MFLAGS) $(DUBUG) -C $(SRCS)/$(SERVER) $(BONUS) MAKEFLAGS=
	@cp -rf $(SRCS)/$(SERVER)/$(SERVER) $(DIR)$(SERVER)

clean :
	@make $(MFLAGS) clean -C $(SRCS)/$(LIBFT)
	@make $(MFLAGS) clean -C $(SRCS)/$(CLIENT)
	@make $(MFLAGS) clean -C $(SRCS)/$(SERVER)

fclean :
	@make $(MFLAGS) fclean -C $(SRCS)/$(LIBFT)
	@make $(MFLAGS) fclean -C $(SRCS)/$(CLIENT)
	@make $(MFLAGS) fclean -C $(SRCS)/$(SERVER)
	@rm -rf $(LIBFT)
	@rm -rf $(CLIENT)
	@rm -rf $(SERVER)

re : fclean all

.PHONY : all clean fclean libft client server