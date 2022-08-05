CLANG = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = replace
SRCS = main.cpp \
		Replace.cpp

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
	rm -rf *.replace

re : fclean all

.PHONY : all clean fclean re
