CLANG = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = a.out
SRCS = main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp

OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

debug : CFLAGS += -g -fsanitize=address
debug : all

%.o : %.cpp
	$(CLANG) $(CFLAGS) -I . -c $< -o $@

$(NAME) : $(OBJS)
	$(CLANG) $(CFLAGS) -I . $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)
	rm -rf *_shrubbery

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
