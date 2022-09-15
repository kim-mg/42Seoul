CC = cc
# CFLAGS = 
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

# test_RC or not
ifdef TEST_FLAG
	DIR_SRCS = ./tests/
else
	DIR_SRCS = ./srcs/
endif

DIR_OBJS = ./objs/
DIR = ./

DIR_LIB = ./lib/
LFLAGS = -L $(DIR_LIB) -lft -lgnl -lftprintf

NAME = cub3D
SRCS = draw_3d.c \
		draw_map.c \
		draw_player.c \
		draw_rays.c \
		error.c \
		free.c \
		init.c \
		key.c \
		layer.c \
		map.c \
		parsing.c \
		parsing_util.c \
		set_game.c \
		texture.c \
		util.c \
		main.c


OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

# test rule
test :
	$(MAKE) TEST_FLAG=1 $(NAME)

all : $(NAME)

debug += CC CFLAGS -g fsanitize=address
debug : all

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
