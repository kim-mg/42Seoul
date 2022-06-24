# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 15:58:51 by myunkim           #+#    #+#              #
#    Updated: 2022/04/25 18:03:01 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIR_OBJS = ./objs/

NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_print_char.c \
	   ft_print_num.c \
	   ft_printf_util.c
OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

all : $(NAME)

$(DIR_OBJS) :
	@mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS) : | $(DIR_OBJS)

$(NAME) : $(OBJS)
	@cp ../libft/libft.a $(NAME)
	@ar rc $@ $(OBJS)

clean :
	rm -rf $(DIR_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
