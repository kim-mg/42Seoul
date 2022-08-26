#include <stdlib.h>
#include <unistd.h>
#include "../lib/libft/libft.h"

// ====================================================================================
// error.c

void	error_exit(char *err)
{
	size_t	size;

	size = ft_strlen(err);
	write(2, "Error\n", 6);
	write(2, err, size);
	write(2, "\n", 1);
	exit(1);
}

// ====================================================================================
// parsing.c
#include <fcntl.h>
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"

enum e_parse_section
{
	PS_TEXTURE,
	PS_LAYER,
	PS_MAP
};

typedef struct s_parser
{
	int	sect;

}t_parser;

void	parsing(char *cub)
{
	int	fd;
	int sect;
	char	*line;
	char	**split;

	sect = 0;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		error_exit("cub file not found");
	line = get_next_line(fd);
	while (line)
	{
		// elem 분류 : texture와 F,C color 그리고 map으로 분류해야 함
		if (sect == PS_TEXTURE || sect == PS_LAYER)
		{
			split = ft_split(line, ' ');
			if (split)
			{
				if (!ft_strncmp(split[0], "NO", ft_strlen(split[0]) + 1))
					ft_printf("NO found\n");
				if (!ft_strncmp(split[0], "SO", ft_strlen(split[0]) + 1))
					ft_printf("SO found\n");
				if (!ft_strncmp(split[0], "WE", ft_strlen(split[0]) + 1))
					ft_printf("WE found\n");
				if (!ft_strncmp(split[0], "EA", ft_strlen(split[0]) + 1))
					ft_printf("EA found\n");
				if (!ft_strncmp(split[0], "F", ft_strlen(split[0]) + 1))
					ft_printf("F found\n");
				if (!ft_strncmp(split[0], "C", ft_strlen(split[0]) + 1))
					ft_printf("C found\n");
			}
			if (sect == PS_TEXTURE && *line == '\n' && ft_strlen(line) == 1)
				sect = PS_LAYER;
			else if (sect == PS_LAYER && *line == '\n' && ft_strlen(line) == 1)
				sect = PS_MAP;
			else
				ft_printf("elem\n");
		}
		if (sect == PS_MAP) {
			ft_printf("map\n");
		}
		
		// 각 분류 사이에 빈 줄이 한 줄 이상 들어감
		// ft_printf(line);
		line = get_next_line(fd);
	}
}

// ====================================================================================
// main.c
#include "../mlx/mlx.h"

enum e_layer_type
{
	LT_CEILING,
	LT_FLOOR
};

typedef struct s_layer	t_layer;

struct s_layer
{
	int	type;
	int	r;
	int	g;
	int	b;
	t_layer	*next;
};

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		w;
	int		h;
}			t_img;

typedef struct s_texture
{
	t_img	n_wall;
	t_img	s_wall;
	t_img	w_wall;
	t_img	e_wall;
}t_texture;

typedef struct s_map
{
	t_layer		*layer_head;
}t_map;

typedef struct s_player
{
	int	x;
	int	y;
}t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	texture;
	t_map		map;
	t_player	player;
}t_game;

void	init_game(t_game *game)
{
	(void)game;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (--argc != 1)
		error_exit("usage : ./cub3D 'map_name.cub'");
	// 0. game init;
	init_game(&game);
	// 1. 입력받은 큐브 데이터 파싱
	parsing(argv[argc]);
	// 2. 게임 실행
	return (0);
}
