# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 18:42:38 by myunkim           #+#    #+#              #
#    Updated: 2022/04/25 16:47:49 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

DIR = ./
DIR_LIBFT = $(DIR)libft
DIR_GNL = $(DIR)get_next_line
DIR_FT_PRINTF = $(DIR)ft_printf

LIBFT = libft.a
GNL	= libgnl.a
FT_PRINTF = libftprintf.a

all : $(LIBFT) $(GNL) $(FT_PRINTF)

$(LIBFT) :
	@$(MAKE) -C $(DIR_LIBFT) MAKEFLAGS=
	@cp -rf $(DIR_LIBFT)/$(LIBFT) $(DIR)$(LIBFT)

$(GNL) :
	@$(MAKE) -C $(DIR_GNL) MAKEFLAGS=
	@cp -rf $(DIR_GNL)/$(GNL) $(DIR)$(GNL)

$(FT_PRINTF) :
	@$(MAKE) -C $(DIR_FT_PRINTF) MAKEFLAGS=
	@cp -rf $(DIR_FT_PRINTF)/$(FT_PRINTF) $(DIR)$(FT_PRINTF)

clean :
	@make clean -C $(DIR_LIBFT)
	@make clean -C $(DIR_GNL)
	@make clean -C $(DIR_FT_PRINTF)

fclean :
	@make fclean -C $(DIR_LIBFT)
	@make fclean -C $(DIR_GNL)
	@make fclean -C $(DIR_FT_PRINTF)
	@rm -rf $(LIBFT)
	@rm -rf $(GNL)
	@rm -rf $(FT_PRINTF)

re : fclean all

.PHONY : all clean fclean libft.a gnl.a 