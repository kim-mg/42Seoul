# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 14:06:48 by myunkim           #+#    #+#              #
#    Updated: 2022/08/03 18:00:21 by myunkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CLANG = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = necromancy
SRCS = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

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
