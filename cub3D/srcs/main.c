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

#define ELEM_COUNT	6

typedef enum e_parse_section
{
	PS_TEXTURE = 1 << 0,
	PS_LAYER = 1 << 2,
	PS_MAP = 1 << 3,
	PS_NOTMAP = 1 << 4,
	PS_DONE = 1 << 5,
}t_parse_section;

typedef struct s_element	t_element;

struct s_element
{
	t_parse_section	sect;
	char			*ident;
	char			*content;
	t_element		*head;
	t_element		*next;
};

typedef struct s_mapping
{
	int		width;
	int		height;
	char	*data;
}t_mapping;

typedef struct s_parser
{
	int			fd;
	char		*line;
	int			sect;
	int			sect_cnt;
	t_element	*elem_head;
	t_mapping	map;
}t_parser;

void	free_split(char **split)
{
	char	**temp;

	temp = split;
	while (*temp)
	{
		free(*temp);
		*temp = NULL;
		temp++;
	}
	free(split);
	split = NULL;
}

t_element	*new_elem(t_element *head, char *ident, char *cont, t_parse_section sect)
{
	t_element	*new;

	new = (t_element *)ft_calloc(sizeof(t_element), 1);
	if (!new)
		return (NULL);
	new->sect = sect;
	new->ident = ft_strdup(ident);
	new->content = ft_strdup(cont);
	new->head = head;
	return (new);
}

void	add_elem(t_element *e_head, char **split, t_parse_section sect)
{
	t_element	*temp;

	if (e_head == NULL)
	{
		e_head = new_elem(NULL, split[0], split[1], sect);
		e_head->head = e_head;
		return ;
	}
	temp = e_head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem(e_head, split[0], split[1], sect);
}

int	get_elem(t_parser *parser, char *line)
{
	char	**split;

	(void)parser;
	(void)line;
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	if (!ft_strncmp(split[0], "NO", ft_strlen(split[0]) + 1))
		add_elem(parser->elem_head, split, PS_TEXTURE);
	else if (!ft_strncmp(split[0], "SO", ft_strlen(split[0]) + 1))
		add_elem(parser->elem_head, split, PS_TEXTURE);
	else if (!ft_strncmp(split[0], "WE", ft_strlen(split[0]) + 1))
		add_elem(parser->elem_head, split, PS_TEXTURE);
	else if (!ft_strncmp(split[0], "EA", ft_strlen(split[0]) + 1))
		add_elem(parser->elem_head, split, PS_TEXTURE);
	else if (!ft_strncmp(split[0], "F", ft_strlen(split[0]) + 1))
		add_elem(parser->elem_head, split, PS_LAYER);
	else if (!ft_strncmp(split[0], "C", ft_strlen(split[0]) + 1))
		add_elem(parser->elem_head, split, PS_LAYER);
	else
	{
		free_split(split);
		return (1);
	}
	free_split(split);
	return (0);
}

void	free_parser(t_parser *parser)
{
	t_element	*temp;
	t_element	*next;

	temp = parser->elem_head;
	while (temp)
	{
		next = temp->next;
		free(temp->ident);
		free(temp->content);
		temp->ident = NULL;
		temp->content = NULL;
		temp->head = NULL;
		temp->next = NULL;
		free(temp);
		temp = next;
	}
	parser->elem_head = NULL;
	if (parser->map.data)
	{
		free(parser->map.data);
		parser->map.data = NULL;
	}
}

void	parse_error_exit(t_parser *parser, char *err)
{
	free_parser(parser);
	error_exit(err);
}

void	parser_init(t_parser *parser)
{
	parser->fd = 0;
	parser->sect = PS_NOTMAP;
	parser->sect_cnt = 0;
	parser->line = "";
	parser->elem_head = NULL;
	parser->map.width = 0;
	parser->map.height = 0;
	parser->map.data = NULL;
}

void	check_section(t_parser *parser)
{
	if (!parser->line)
		parser->sect = PS_DONE;
	if (parser->sect == PS_NOTMAP)
	{
		while (*parser->line == '\n')
		{
			free(parser->line);
			parser->line = get_next_line(parser->fd);
			if (*parser->line != '\n')
				parser->sect_cnt++;
		}
		if (parser->sect_cnt >= 2)
			parser->sect = PS_MAP;
	}
}

void	get_map(t_parser *parser, char *line)
{
	int		len;
	char	*new;

	len = ft_strlen(line);
	new = NULL;
	if (*line == '\n')
		parse_error_exit(parser, "map has empty line");
	if (parser->map.width == 0 || len > parser->map.width)
		parser->map.width = len;
	if (!parser->map.data)
		parser->map.data = ft_strdup(line);
	else
	{
		new = ft_strjoin(parser->map.data, "\n");
		free(parser->map.data);
		parser->map.data = ft_strjoin(new, line);
		free(new);
	}
	parser->map.height++;
}

int	parsing(char *cub)
{
	t_parser	parser;

	// (void)game;
	parser_init(&parser);
	parser.fd = open(cub, O_RDONLY);
	if (parser.fd < 0)
		error_exit("cub file not found");
	while (parser.line && parser.sect != PS_DONE)
	{
		parser.line = get_next_line(parser.fd);
		check_section(&parser);
		if (parser.sect == PS_NOTMAP)
			if (get_elem(&parser, parser.line))
				parse_error_exit(&parser, "not enough elements");
		// if (parser.sect == PS_MAP)
			// get_map(&parser, parser.line);
		free(parser.line);
	}
	free_parser(&parser);
	return (0);
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
	// parsing(argv[argc], &game);
	parsing(argv[argc]);
	// 2. 게임 실행
	return (0);
}
