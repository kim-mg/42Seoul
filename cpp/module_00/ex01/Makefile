# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 14:06:48 by myunkim           #+#    #+#              #
#    Updated: 2022/06/29 16:44:01 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CLANG = clang++
CFLAGS = -Wall -Wextra -Werror

NAME = phonebook
SRCS = main.cpp

OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

%.o : %.c
	$(CLANG) $(CFLAGS) -I -c $< -o $@

$(NAME) : $(OBJS)
	$(CLANG) $(CFLAGS) -I . $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
