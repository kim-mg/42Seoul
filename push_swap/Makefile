# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 14:59:58 by myunkim           #+#    #+#              #
#    Updated: 2022/03/05 00:06:15 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs
DIR			= ./
DEBUG		=

CHECKER		= checker
PUSH_SWAP	= push_swap

RM			= rm -rf

all : $(CHECKER) $(PUSH_SWAP)

debug : DEBUG += debug
debug : all

$(CHECKER) :
	$(MAKE) $(DEBUG) -C $(SRCS)/$(CHECKER) MAKEFLAGS=
	cp -rf $(SRCS)/$(CHECKER)/$(CHECKER) $(DIR)$(CHECKER)

$(PUSH_SWAP) :
	$(MAKE) $(DEBUG) -C $(SRCS)/$(PUSH_SWAP) MAKEFLAGS=
	cp -rf $(SRCS)/$(PUSH_SWAP)/$(PUSH_SWAP) $(DIR)$(PUSH_SWAP)

clean :
	make clean -C $(SRCS)/$(CHECKER)
	make clean -C $(SRCS)/$(PUSH_SWAP)

fclean :
	make fclean -C $(SRCS)/$(CHECKER)
	make fclean -C $(SRCS)/$(PUSH_SWAP)
	$(RM) $(CHECKER)
	$(RM) $(PUSH_SWAP)

re : fclean all

.PHONY : all clean fclean checker push_swap
