CC = gcc
CFLAGS = -Wall -Wextra -Werror

OS = $(shell uname)

ifeq ($(OS), Darwin)
	MLX = ./mlx
	LINK = -L $(MLX) -lmlx -framework OpenGL -framework Appkit
else
	MLX = ./minilibx-linux
	LINK = -L $(MLX) -lmlx -lm -lXext -lX11
endif

DIR_HEADERS = ./includes/
DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
DIR = ./

DIR_LIB = ./lib/
LFLAGS = -L $(DIR_LIB) -lft -lgnl -lftprintf

NAME = so_long
SRCS = so_long.c \
		draw_map.c \
		error.c \
		get_comp.c \
		ingame.c \
		parse_map.c \
		read_map.c \
		set_game.c

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

all : $(NAME)

$(DIR_OBJS) :
	@$(MAKE) -C $(DIR_LIB) MAKEFLAGS=
	mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.c
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(OBJS) : | $(DIR_OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLGAS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME) $(LFLAGS) $(LINK)

clean :
	@make clean -C $(DIR_LIB)
	rm -rf $(DIR_OBJS)

fclean : clean
	@make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re