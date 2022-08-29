#include <stdlib.h>
#include <unistd.h>
#include "../lib/libft/libft.h"
#include "../mlx/mlx.h"

#define TILE_SIZE	50

typedef struct s_layer
{
	int	color;
}t_layer;

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
	int		cols;
	int		rows;
	char	*coord;
	t_layer	ceiling;
	t_layer	floor;
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

typedef enum e_identity
{
	ID_NORTH = 1 << 0,
	ID_SOUTH = 1 << 1,
	ID_WEST = 1 << 2,
	ID_EAST = 1 << 3,
	ID_CEILING = 1 << 4,
	ID_FLOOR = 1 << 5,
}t_identity;

typedef enum e_parse_section
{
	PS_TEXTURE,
	PS_LAYER,
	PS_MAP,
	PS_NOTMAP,
	PS_DONE,
}t_parse_section;

typedef struct s_element	t_element;

struct s_element
{
	t_parse_section	sect;
	t_identity		ident;
	char			*content;
	t_element		*head;
	t_element		*next;
};

typedef struct s_map_data
{
	int		width;
	int		height;
	char	*data;
}t_map_data;

typedef struct s_parser
{
	int			fd;
	char		*line;
	int			sect;
	int			sect_cnt;
	int			elem_cnt;
	t_element	*elem_head;
	t_map_data	map;
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

t_element	*new_elem(t_element *head, char *cont, t_parse_section sect, t_identity ident)
{
	t_element	*new;

	new = (t_element *)ft_calloc(sizeof(t_element), 1);
	if (!new)
		return (NULL);
	new->sect = sect;
	new->ident = ident;
	new->content = cont;
	if (head)
		new->head = head;
	else
		new->head = NULL;
	new->next = NULL;
	return (new);
}

void	add_elem(t_element **e_head, char *cont, t_parse_section sect, t_identity ident)
{
	t_element	*temp;

	if (!(*e_head))
	{
		*e_head = new_elem(NULL, cont, sect, ident);
		(*e_head)->head = *e_head;
		return ;
	}
	temp = *e_head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem(*e_head, cont, sect, ident);
}

int	get_elem(t_parser *parser, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (1);
	if (!ft_strncmp(split[0], "NO", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_NORTH);
	else if (!ft_strncmp(split[0], "SO", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_SOUTH);
	else if (!ft_strncmp(split[0], "WE", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_WEST);
	else if (!ft_strncmp(split[0], "EA", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_EAST);
	else if (!ft_strncmp(split[0], "F", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_LAYER, ID_FLOOR);
	else if (!ft_strncmp(split[0], "C", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_LAYER, ID_CEILING);
	else
	{
		free_split(split);
		return (1);
	}
	parser->elem_cnt++;
	free(split);
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
		free(temp->content);
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
	parser->elem_cnt = 1;
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
		if (parser->sect_cnt >= 2 && parser->elem_cnt >= 6)
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

t_element	*find_elem(t_element *head, t_identity ident)
{
	while (head)
	{
		if (head->ident == ident)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	game_error_exit(t_game *game, t_parser *parser, char *err)
{
	if (parser)
		free_parser(parser);
	if (game->map.coord)
	{
		free(game->map.coord);
		game->map.coord = NULL;
	}
	error_exit(err);
}

t_img	xpm_to_img(t_game *game, char *file, t_parser *parser)
{
	char	*path;
	t_img	img;

	path = ft_strjoin("./texture/", file);
	img.ptr = mlx_xpm_file_to_image(game->mlx, path, &img.w, &img.h);
	free(path);
	if (!img.ptr)
		game_error_exit(game, parser, "xpm file not found");
	return (img);
}

int valid_elem(t_parser *parser, t_parse_section sect)
{
	int	rst;
	t_element	*temp;

	rst = 0;
	temp = parser->elem_head;
	while (temp)
	{
		if (temp->sect == sect)
			rst |= temp->ident;
		temp = temp->next;
	}
	if (sect == PS_TEXTURE)
		if (rst != (ID_NORTH | ID_SOUTH | ID_WEST | ID_EAST))
			return (1);
	if (sect == PS_LAYER)
		if (rst != (ID_CEILING | ID_FLOOR))
			return (1);
	return (0);
}

void	set_texture(t_parser *parser, t_game *game)
{
	if (valid_elem(parser, PS_TEXTURE))
		game_error_exit(game, parser, "texture element unsatisfied");
	game->texture.n_wall = xpm_to_img(game, find_elem(parser->elem_head, ID_NORTH)->content, parser);
	game->texture.s_wall = xpm_to_img(game, find_elem(parser->elem_head, ID_SOUTH)->content, parser);
	game->texture.w_wall = xpm_to_img(game, find_elem(parser->elem_head, ID_WEST)->content, parser);
	game->texture.e_wall = xpm_to_img(game, find_elem(parser->elem_head, ID_EAST)->content, parser);
}

int	convert_rgb(char *data)
{
	int		rtn;
	int		idx;
	int		temp[3];
	char	**rgb;

	rtn = 0;
	rgb = ft_split(data, ',');
	idx = 0;
	while (rgb[idx])
	{
		temp[idx] = ft_atoi(rgb[idx]);
		while (temp[idx])
		{
			rtn *= 16;
			if (temp[idx] / 16)
				rtn += temp[idx] / 16;
			else
				rtn += temp[idx] % 16;
			temp[idx] /= 16;
		}
		idx++;
	}
	ft_printf("color : %d", rtn);
	return (rtn);
}

void	set_layer(t_parser *parser, t_game *game)
{
	if (valid_elem(parser, PS_LAYER))
		game_error_exit(game, parser, "texture element unsatisfied");
	game->map.ceiling.color = convert_rgb(find_elem(parser->elem_head, ID_CEILING)->content);
	game->map.floor.color = 0;
}

// void	set_map(t_parser *parser, t_game *game)
// {
// 	// valid_map
// 	//
// }

// void	data_to_map(t_parser *parser, t_game *game)
// {
// 	(void)game;
// 	(void)parser;
// 	// set_texture
// 	// set_layer
// 	// set_map
// }

void	parse_cub(char *cub, t_parser *parser)
{
	parser_init(parser);
	parser->fd = open(cub, O_RDONLY);
	if (parser->fd < 0)
		error_exit("cub file not found");
	while (parser->line && parser->sect != PS_DONE)
	{
		parser->line = get_next_line(parser->fd);
		check_section(parser);
		if (parser->sect == PS_NOTMAP)
			if (get_elem(parser, parser->line))
				parse_error_exit(parser, "illegal element");
		if (parser->sect == PS_MAP)
			get_map(parser, parser->line);
		free(parser->line);
	}
}

// ====================================================================================
// main.c
void	init_game(t_game *game)
{
	// map
	game->map.cols = 0;
	game->map.rows = 0;
	game->map.coord = NULL;
	game->map.ceiling.color = 0;
	game->map.floor.color = 0;
	// player
	game->player.x = 0;
	game->player.y = 0;
}

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("init error : mlx init failed.");
	width = game->map.cols * TILE_SIZE;
	height = game->map.rows * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		error_exit("init error : window init failed.");
}

void	set_game(t_game *game, char *data)
{
	t_parser	parser;

	init_game(game);
	parse_cub(data, &parser);
	// set_map(&parser, game);
	// init_window(game);
	// set_texture(&parser, game);
	set_layer(&parser, game);
	free_parser(&parser);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (--argc != 1)
		error_exit("usage : ./cub3D 'map_name.cub'");
	// 1. 게임 세팅;
	set_game(&game, argv[argc]);
	// 2. 게임 실행
	// execute_game(&game);
	return (0);
}
