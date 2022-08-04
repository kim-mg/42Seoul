# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 14:06:48 by myunkim           #+#    #+#              #
#    Updated: 2022/08/04 00:30:13 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CLANG = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = attack
SRCS = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		# HumanB.cpp

OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

debug : CFLAGS += -g fsanitize=address
debug : all

%.o : %.cpp
	$(CLANG) $(CFLAGS) -I . -c $< -o $@

$(NAME) : $(OBJS)
	$(CLANG) $(CFLAGS) -I . $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
