#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "../lib/libft/libft.h"
#include "../mlx/mlx.h"
// #include "../minilibx-linux/mlx.h"
#include <stdio.h>

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_DESTROY_NOTIFY	17

#define TILE_SIZE	64
#define MINIMAP_SIZE	64

# define TO_COORD(X, Y, W) ((int)floor(Y) * W + (int)floor(X))

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

	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_texture
{
	int		get_texture;
	t_img	n_wall;
	t_img	s_wall;
	t_img	w_wall;
	t_img	e_wall;
}t_texture;

typedef struct s_map
{
	int		cols;
	int		rows;
	int		width;
	int		height;
	char	**coord;
	char	sight;
	t_layer	ceiling;
	t_layer	floor;
}t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	raydir_x;
	double	raydir_y;
	int		side;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		map_x;
	int		map_y;

	double	mov_spd;
	double	rot_spd;

	double	time;
	double	old_time;
}t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	texture;
	t_map		map;
	t_player	player;
	
	t_img		img;
}t_game;


// =============================================================================
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

// =============================================================================
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

void	free_strarr(char **arr)
{
	char	**temp;

	temp = arr;
	while (*temp)
	{
		free(*temp);
		*temp = NULL;
		temp++;
	}
	free(arr);
	arr = NULL;
}

t_element	*new_elem(t_element *head, char *cont, t_parse_section sect, t_identity ident)
{
	t_element	*new;

	new = (t_element *)ft_calloc(sizeof(t_element), 1);
	if (!new)
		return (NULL);
	new->sect = sect;
	new->ident = ident;
	new->content = ft_strtrim(cont, "\n");
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

char	**pre_proc_elem(char *line)
{
	char	**rtn;
	char	*temp;
	int	i;

	rtn = ft_split(line, ' ');
	i = 0;
	while (*(rtn + i))
		i++;
	if (i < 2 || 5 < i)
	{
		free_strarr(rtn);
		return (NULL);
	}
	if (2 < i && i < 5)
	{
		i = 2;
		while (*(rtn + i))
		{
			temp = rtn[1];
			rtn[1] = ft_strjoin(temp, *(rtn + i++));
			free(temp);
		}
	}
	return (rtn);
}

int	get_elem(t_parser *parser, char *line)
{
	char	**split;

	split = pre_proc_elem(line);
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
		free_strarr(split);
		return (1);
	}
	parser->elem_cnt++;
	free_strarr(split);
	return (0);
}

void	free_parser(t_parser *parser)
{
	t_element	*temp;
	t_element	*next;

	if (!parser)
		return ;
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

void	get_map_data(t_parser *parser, char *line)
{
	int		len;
	char	*new;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len -= 1;
	new = NULL;
	if (*line == '\n')
		parse_error_exit(parser, "map has empty line");
	if (parser->map.width == 0 || len > parser->map.width)
		parser->map.width = len;
	if (!parser->map.data)
		parser->map.data = ft_strdup(line);
	else
	{
		new = ft_strjoin(parser->map.data, line);
		free(parser->map.data);
		parser->map.data = new;
	}
	parser->map.height++;
}

void	parse_cub(t_parser *parser, char *cub)
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
			get_map_data(parser, parser->line);
		free(parser->line);
	}
}

// ====================================================================================
// main.c
enum e_key_setting
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
};

// enum e_ubuntu_key
// {
// 	KEY_ESC = 0xff1b,
// 	KEY_W = 0x77,
// 	KEY_A = 0x61,
// 	KEY_S = 0x73,
// 	KEY_D = 0x64,
// };

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	// map
	game->map.cols = 0;
	game->map.rows = 0;
	game->map.coord = NULL;
	game->map.sight = 0;
	game->map.ceiling.color = 0;
	game->map.floor.color = 0;
	// player
	game->player.pos_x = 0;
	game->player.pos_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	
	game->player.mov_spd = 0;
	game->player.rot_spd = 0;

	game->player.time = 0;
	game->player.old_time = 0;
	// texture
	game->texture.get_texture = 0;
}

void	free_game(t_game *game)
{
	char	**temp;

	temp = game->map.coord;
	if (game->map.coord)
	{
		while (*temp)
		{
			free(*temp);
			*temp = NULL;
			temp++;
		}
		free(game->map.coord);
		game->map.coord = NULL;
	}
	if (game->texture.get_texture)
	{
		mlx_destroy_image(game->mlx, game->texture.n_wall.ptr);
		mlx_destroy_image(game->mlx, game->texture.s_wall.ptr);
		mlx_destroy_image(game->mlx, game->texture.w_wall.ptr);
		mlx_destroy_image(game->mlx, game->texture.e_wall.ptr);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
}

void	game_error_exit(t_game *game, t_parser *parser, char *err)
{
	free_parser(parser);
	free_game(game);
	error_exit(err);
}


int	valid_wall(t_map *map, int i, int j)
{
	if ((i == 0 || j == 0 || i == map->rows - 1 || j == map->cols - 1)
		&& map->coord[i][j] == '0')
		return (1);
	if (i != 0 && j != 0 && i != map->rows - 1
		&& j != map->cols - 1&& map->coord[i][j] == ' ')
		if (map->coord[i][j - 1] == '0' || map->coord[i - 1][j] == '0'
			|| map->coord[i][j + 1] == '0' || map->coord[i + 1][j] == '0')
			return (1);
	return (0);
}

int	valid_compo(t_map *map, int i, int j)
{
	char	*chr;

	chr = ft_strchr("NSWE", map->coord[i][j]);
	if (map->sight && chr)
		return (1);
	if (!ft_strchr(" 01NSWE", map->coord[i][j]))
		return (1);
	if ((i == 0 || j == 0 || i == map->rows - 1 || j == map->cols - 1)
		&& chr)
		return (1);
	if (i != 0 && j != 0 && i != map->rows - 1 && j != map->cols - 1
		&& chr)
		if (map->coord[i][j - 1] == ' ' || map->coord[i - 1][j] == ' '
			|| map->coord[i][j + 1] == ' ' || map->coord[i + 1][j] == ' ')
			return (1);
	if (chr && map->sight == 0)
		map->sight = *ft_strchr("NSWE", map->coord[i][j]);
	return (0);
}

int	valid_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->coord[++i])
	{
		j = -1;
		while (map->coord[i][++j])
		{
			if (valid_wall(map, i, j))
				return (1);
			if (valid_compo(map, i, j))
				return (1);
		}
	}
	if (map->sight == 0)
		return (1);
	return (0);
}

void	copy_map(char *map, char *data, int len)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (data[++i])
		map[i] = data[i];
	while (i < len)
		map[i++] = ' ';
	map[i] = '\0';
}

char	**mapping(t_map_data *map)
{
	char	**rtn;
	char	**data;
	int		h;

	rtn = (char **)ft_calloc(sizeof(char *), map->height + 1);
	if (!map)
		return (NULL);
	h = -1;
	data = ft_split(map->data, '\n');
	while (++h < map->height)
	{
		rtn[h] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!rtn[h] || !data)
		{
			free_strarr(rtn);
			return (NULL);
		}
		copy_map(rtn[h], data[h], map->width - 1);
	}
	free_strarr(data);
	return (rtn);
}

void	set_map(t_parser *parser, t_game *game)
{
	game->map.rows = parser->map.height;
	game->map.cols = parser->map.width;
	game->map.width = parser->map.width * TILE_SIZE;
	game->map.height = parser->map.height * TILE_SIZE;
	game->map.coord = mapping(&parser->map);
	if (!game->map.coord)
		game_error_exit(game, parser, "map malloc fail");
	if (valid_map(&game->map))
		game_error_exit(game, parser, "invalid map configuration");
}

int	set_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	width = game->map.cols * TILE_SIZE;
	height = game->map.height;
	game->win = mlx_new_window(game->mlx, width, height, "cub3D");
	if (!game->win)
		return (1);
	return (0);
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
	game->texture.get_texture = 1;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	convert_rgb(char *data)
{
	int		rtn;
	char	**rgb;

	rtn = 0;
	rgb = ft_split(data, ',');
	rtn = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_strarr(rgb);
	return (rtn);
}

void	set_layer(t_parser *parser, t_game *game)
{
	if (valid_elem(parser, PS_LAYER))
		game_error_exit(game, parser, "texture element unsatisfied");
	game->map.ceiling.color = convert_rgb(find_elem(parser->elem_head, ID_CEILING)->content);
	game->map.floor.color = convert_rgb(find_elem(parser->elem_head, ID_FLOOR)->content);
}

void	set_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (ft_strchr("NSWE", game->map.coord[i][j]))
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
			}
		}
	}
	// printf("p.x : %f\tp.y : %f\n", game->player.x, game->player.y);
}

void	set_game(t_game *game, char *data)
{
	t_parser	parser;

	init_game(game);
	parse_cub(&parser, data);
	set_map(&parser, game);
	if (set_window(game))
		game_error_exit(game, &parser, "mlx or window init failed");
	set_texture(&parser, game);
	set_layer(&parser, game);
	set_player(game);
	free_parser(&parser);
}

void	valid_extension(const char *cub)
{
	char	*temp;

	temp = ft_strnstr(cub, ".cub", ft_strlen(cub));
	if (!temp || (temp && ft_strncmp(temp, ".cub", ft_strlen(temp) + 1)))
		error_exit("invalid extension");
}

int	deal_key(int key_code, t_game *game)
{
	char	**coord = game->map.coord;
	t_player	*p;

	(void)game;
	p = &game->player;
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
	{
		if (coord[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * p->mov_spd)] != '1')
			p->pos_x += p->dir_x * p->mov_spd;
		if (coord[(int)(p->pos_y + p->dir_y * p->mov_spd)][(int)(p->pos_x)] != '1')
			p->pos_y += p->dir_y * p->mov_spd;
	}
	if (key_code == KEY_S)
	{
		if (coord[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x * p->mov_spd)] != '1')
			p->pos_x -= p->dir_x * p->mov_spd;
		if (coord[(int)(p->pos_y - p->dir_y * p->mov_spd)][(int)(p->pos_x)] != '1')
			p->pos_y -= p->dir_y * p->mov_spd;
	}
	if (key_code == KEY_D)
	{
		double	old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_spd) - p->dir_y * sin(p->rot_spd);
		p->dir_y = old_dir_x * sin(p->rot_spd) + p->dir_y * cos(p->rot_spd);
		double	old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(p->rot_spd) - p->plane_y * sin(p->rot_spd);
		p->plane_y = old_plane_x * sin(p->rot_spd) + p->plane_y * cos(p->rot_spd);
	}
	if (key_code == KEY_A)
	{
		double	old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->rot_spd) - p->dir_y * sin(-p->rot_spd);
		p->dir_y = old_dir_x * sin(-p->rot_spd) + p->dir_y * cos(-p->rot_spd);
		double	old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-p->rot_spd) - p->plane_y * sin(-p->rot_spd);
		p->plane_y = old_plane_x * sin(-p->rot_spd) + p->plane_y * cos(-p->rot_spd);
	}
	// printf("dir_x: %f\tdir_y: %f\tplane_x: %f\tplane_y: %f\n", p->dir_x, p->dir_y, p->plane_x, p->plane_y);
	return (0);
}

int	close_btn_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY));
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[(int)floor(y1) * game->map.width + (int)floor(x1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_game *game)
{
	int	i;
	int	j;
	int	s;

	s = MINIMAP_SIZE;
	i = -1;
	while (++i < game->map.cols)
		draw_line(game, i * s, 0, i * s, game->map.rows * s);
	draw_line(game, game->map.cols * s - 1, 0, game->map.cols * s - 1, game->map.rows * s);
	j = -1;
	while (++j < game->map.rows)
		draw_line(game, 0, j * s, game->map.cols * s, j * s);
	draw_line(game, 0, game->map.rows * s - 1, game->map.cols * s, game->map.rows * s - 1);
}

void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	s;

	s = MINIMAP_SIZE;
	x *= s;
	y *= s;
	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
			game->img.data[(y + i) * game->map.width + x + j] = color;
	}
}

void	draw_rectangles(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.coord[i][j] == '1')
				draw_rectangle(game, j, i, 0xFFFFFF);
			if (game->map.coord[i][j] != '1')
				draw_rectangle(game, j, i, 0x000000);
		}
	}
}

void	draw_player_pixels(t_game *game, int x, int y)
{
	int	i;
	int	j;
	double	p_x;
	double	p_y;
	int	s;
	
	s = MINIMAP_SIZE;
	p_x = (game->player.pos_x - x) * s;
	p_y = (game->player.pos_y - y) * s;
	x *= s;
	y *= s;
	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
			if ((p_y - 4 < i && i < p_y + 4) && (p_x - 4 < j && j < p_x + 4))
				game->img.data[(y + i) * game->map.width + x + j] = 0xFF0000;
	}
}

void	draw_player_all_position(t_game *game, int x, int y)
{
	if (game->map.coord[y - 1][x] != '1')
		draw_player_pixels(game, x, y - 1);
	if (game->map.coord[y + 1][x] != '1')
		draw_player_pixels(game, x, y + 1);
	if (game->map.coord[y][x - 1] != '1')
		draw_player_pixels(game, x - 1, y);
	if (game->map.coord[y][x + 1] != '1')
		draw_player_pixels(game, x + 1, y);
	if (game->map.coord[y - 1][x - 1] != '1')
		draw_player_pixels(game, x - 1, y - 1);
	if (game->map.coord[y + 1][x - 1] != '1')
		draw_player_pixels(game, x - 1, y + 1);
	if (game->map.coord[y - 1][x + 1] != '1')
		draw_player_pixels(game, x + 1, y - 1);
	if (game->map.coord[y + 1][x + 1] != '1')
		draw_player_pixels(game, x + 1, y + 1);
	draw_player_pixels(game, x, y);
}

void	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
			if ((int)game->player.pos_x == j && (int)game->player.pos_y == i)
				draw_player_all_position(game, j, i);
	}
}

void	test_img_init(t_game *game)
{
	game->img.ptr = mlx_new_image(game->mlx, game->map.width, game->map.height);
	game->img.data = (int *)mlx_get_data_addr(game->img.ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}


// =========================================================================================
void	set_deltadist(t_player *p)
{
	if (!p->raydir_x)
		p->deltadist_x = 1e30;
	else
		p->deltadist_x = fabs(1 / p->raydir_x);
	if (!p->raydir_y)
		p->deltadist_y = 1e30;
	else
		p->deltadist_y = fabs(1 / p->raydir_y);
}

void	set_sidedist(t_player *p)
{
	if (p->raydir_x < 0)
	{
		p->step_x = -1;
		p->sidedist_x = (p->pos_x - (int)p->pos_x) * p->deltadist_x;
	}
	else
	{
		p->step_x = 1;
		p->sidedist_x = ((int)p->pos_x - p->pos_x + 1.0) * p->deltadist_x;
	}
	if (p->raydir_y < 0)
	{
		p->step_y = -1;
		p->sidedist_y = (p->pos_y - (int)p->pos_y) * p->deltadist_y;
	}
	else
	{
		p->step_y = 1;
		p->sidedist_y = ((int)p->pos_y - p->pos_y + 1.0) * p->deltadist_y;
	}
}

void	set_ray(t_player *p, double camera_x)
{
	p->map_x = (int)p->pos_x;
	p->map_y = (int)p->pos_y;
	p->raydir_x = p->dir_x + p->plane_x * camera_x;
	p->raydir_y = p->dir_y + p->plane_y * camera_x;
	set_deltadist(p);
	set_sidedist(p);
}

double	get_dist(t_game *game)
{
	while (1)
	{
		if (game->player.sidedist_x < game->player.sidedist_y)
		{
			game->player.sidedist_x += game->player.deltadist_x;
			game->player.map_x += game->player.step_x;
			game->player.side = 0;
		}
		else
		{
			game->player.sidedist_y += game->player.deltadist_y;
			game->player.map_y += game->player.step_y;
			game->player.side = 1;
		}
		if (game->map.coord[game->player.map_y][game->player.map_x] == '1')
			break ;
	}
	if (!game->player.side)
		return (game->player.sidedist_x - game->player.deltadist_x);
	else
		return (game->player.sidedist_y - game->player.deltadist_y);
}



int verLine(int x, int y1, int y2, int color, t_game *g)
{
	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
	if(y2 < 0 || y1 >= g->map.height  || x < 0 || x >= g->map.width) return 0; //no single point of the line is on screen
	if(y1 < 0) y1 = 0; //clip
	if(y2 >= g->map.width) y2 = g->map.height - 1; //clip

	for(int y = y1; y <= y2; y++)
		g->img.data[y * g->map.width + x] = color;
	return 1;
}

void	draw_3d(t_game *game)
{
	for (int x = 0; x < game->map.width; ++x)
	{
		// ray 위치와 방향 계산
		double	camera_x = 2 * x / (double)game->map.width - 1;
		double	rayDir_x = game->player.dir_x + game->player.plane_x * camera_x;
		double	rayDir_y = game->player.dir_y + game->player.plane_y * camera_x;
		
		// 맵에서의 위치
		int map_x = (int)game->player.pos_x;
		int map_y = (int)game->player.pos_y;
		
		// 현재 위치에서 다음 x측 또는 y측까지 ray의 거리
		double	sideDist_x;
		double	sideDist_y;

		//
		double	deltaDist_x = (rayDir_x == 0) ? 1e30 : fabs(1 / rayDir_x);
		double	deltaDist_y = (rayDir_y == 0) ? 1e30 : fabs(1 / rayDir_y);

		double	perp_wall_dist;

		// x와 y의 방향
		int	step_x;
		int	step_y;

		int	hit = 0; // ray가 벽에 맞았는지
		int	side; // ray가 벽의 옆면에 맞았는지
		// step과 sideDist를 계산
		if (rayDir_x < 0)
		{
			step_x = -1;
			sideDist_x = (game->player.pos_x - map_x) * deltaDist_x;
		}
		else
		{
			step_x = 1;
			sideDist_x = (map_x + 1.0 - game->player.pos_x) * deltaDist_x;
		}
		if (rayDir_y < 0)
		{
			step_y = -1;
			sideDist_y = (game->player.pos_y - map_y) * deltaDist_y;
		}
		else
		{
			step_y = 1;
			sideDist_y = (map_y + 1.0 - game->player.pos_y) * deltaDist_y;
		}
		// DDA 알고리즘으로 ray가 벽에 맞았는지 계산
		while (hit == 0)
		{
			// x축 방향과 y축 방향으로 단위 블럭씩 넘겨 뜀
			if (sideDist_x < sideDist_y)
			{
				sideDist_x += deltaDist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				sideDist_y += deltaDist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map.coord[map_y][map_x] == '1')
				hit = 1;
		}

		//
		if (side == 0)
			perp_wall_dist = (sideDist_x - deltaDist_x);
		else
			perp_wall_dist = (sideDist_y - deltaDist_y);

		//
		int	line_height = (int) (game->map.height / perp_wall_dist);

		//
		int	draw_start = -line_height / 2 + game->map.height / 2;
		if (draw_start < 0)
			draw_start = 0;
		int	draw_end = line_height / 2 + game->map.height / 2;
		if (draw_end >= game->map.height)
			draw_end = game->map.height - 1;

		//
		int	color;
		switch (game->map.coord[map_y][map_x])
		{
		case '1':
			color = 0xFFFFFF;
			break;
		case '0':
			color = 0x000000;
		default:
			break;
		}

		//
		if (side == 1)
			color = color / 2;

		// draw pixels
		verLine(x, draw_start, draw_end, color, game);
	}
}

void	draw_ray(t_game *game, int x, int y, int base_x)
{
	double	wall_x;
	double	wall_y;
	double	p_pos[2];

	(void)base_x;
	p_pos[0] = game->player.pos_x * MINIMAP_SIZE;
	p_pos[1] = game->player.pos_y * MINIMAP_SIZE;
	// wall_x = p_pos[0] + (game->player.sidedist_x * game->player.step_x * TILE_SIZE);
	// wall_y = p_pos[1] + (game->player.sidedist_y * game->player.step_y * TILE_SIZE);
	wall_x = game->player.map_x * MINIMAP_SIZE;
	wall_y = game->player.map_y * MINIMAP_SIZE;
	// printf("wall_x: %f\twall_y: %f\n", wall_x, wall_y);
	// if (game->player.step_x == 1 && game->player.step_y == 1)
	// 	if (p_pos[0] <= x && x < wall_x && p_pos[1] <= y && y < wall_y)
	// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
	// if (game->player.step_x == 1 && game->player.step_y == -1)
	// 	if (p_pos[0] <= x && x < wall_x && wall_y <= y && y <= p_pos[1])
	// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
	// if (game->player.step_x == -1 && game->player.step_y == 1)
	// 	if (wall_x <= x && x < p_pos[0] && p_pos[1] <= y && y < wall_y)
	// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
	// if (game->player.step_x == -1 && game->player.step_y == -1)
	// 	if (wall_x <= x && x < p_pos[0] && wall_y <= y && y <= p_pos[1])
	// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
	// if (base_x)
	// {
	// 	if (game->player.step_x == 1)
	// 		if (game->player.pos_y * TILE_SIZE <= y && y <= game->player.map_y * TILE_SIZE)
	// 			game->img.data[y * game->map.width + x] = 0xFFFF00;
	// 	if (game->player.step_x == -1)
	// 		if ((game->player.map_y + 1) * TILE_SIZE <= y && y <= game->player.pos_y * TILE_SIZE)
	// 			game->img.data[y * game->map.width + x] = 0xFFFF00;
	// }
	if (base_x)
	{
		// if (game->player.step_y == 1 && p_pos[1] <= y && y < game->player.map_y * MINIMAP_SIZE)
		// 	if (0 < x && x < game->map.width)
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
		// if (game->player.step_y == -1 && (game->player.map_y + 1) * MINIMAP_SIZE < y && y <= p_pos[1])
		// 	if (0 < x && x < game->map.width)
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;

		// if (game->player.step_y == 1 && p_pos[1] <= y && y < game->player.map_y * MINIMAP_SIZE)
		// 	if (0 < x && x < game->map.width)
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
		// if (game->player.step_y == -1 && (game->player.map_y + 1) * MINIMAP_SIZE <= y && y <= p_pos[1])
		// 	if (0 < x && x < game->map.width)
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
		

		// if (game->player.step_x == 1 && p_pos[0] <= x && x < game->player.map_x * MINIMAP_SIZE)
		// {
			
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
		// }	
		// if (game->player.step_x == -1 && (game->player.map_x + 1) * MINIMAP_SIZE < x && x <= p_pos[0])
		// {
		// 	if (game->player.step_y == 1 && p_pos[1] <= y && y < game->player.map_y * MINIMAP_SIZE)
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
		// 	if (game->player.step_y == -1 && (game->player.map_y + 1) * MINIMAP_SIZE <= y && y <= p_pos[1])
		// 		game->img.data[y * game->map.width + x] = 0xFFFF00;
		// }
	}
	if (!base_x)
	{
		// if (0 <= y && y < game->map.height)
		// 	game->img.data[y * game->map.width + x] = 0xFFFF00;

		if (game->player.step_x == 1 && p_pos[0] <= x && x < game->player.map_x * MINIMAP_SIZE)
			if (0 < y && y < game->map.height)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
		if (game->player.step_x == -1 && (game->player.map_x + 1) * MINIMAP_SIZE < x && x <= p_pos[0])
			if (0 < y && y < game->map.height)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
		if (game->player.step_y == 1)
			if (p_pos[1] <= y && y <= game->player.map_y * MINIMAP_SIZE)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
		if (game->player.step_y == -1)
			if ((game->player.map_y + 1) * MINIMAP_SIZE <= y && y <= p_pos[1])
				game->img.data[y * game->map.width + x] = 0xFFFF00;
	}
}

void	draw_ray_y(t_game *game, double raydir_x, double raydir_y)
{
	int		i;
	int		y;
	double	m;
	double	p_pos[2];

	p_pos[0] = game->player.pos_x * MINIMAP_SIZE;
	p_pos[1] = game->player.pos_y * MINIMAP_SIZE;
	m = raydir_y / raydir_x;
	i = -1;
	while (++i < game->map.width)
	{
		int	top = game->player.map_x * MINIMAP_SIZE;
		int	bottom = (game->player.map_x + 1) * MINIMAP_SIZE;
		y = (int)(m * (i - p_pos[0]) + p_pos[1]);
		if ((raydir_x >= 0 && raydir_y >= 0)
			&& p_pos[0] <= i && i < top)
			game->img.data[y * game->map.width + i] = 0xFFFF00;
		if ((raydir_x >= 0 && raydir_y <= 0)
			&& p_pos[0] <= i && i < top)
			game->img.data[y * game->map.width + i] = 0xFFFF00;
		if ((raydir_x <= 0 && raydir_y >= 0)
			&& bottom <= i && i < p_pos[0])
			game->img.data[y * game->map.width + i] = 0xFFFF00;
		if ((raydir_x <= 0 && raydir_y <= 0)
			&& bottom <= i &&  i < p_pos[0])
			game->img.data[y * game->map.width + i] = 0xFFFF00;

		// if (game->player.step_x > 0 && game->player.step_y > 0 && p_pos[0] <= i)
		// 	draw_ray(game, i, y, 0);
	}
}

void	draw_ray_x(t_game *game, double raydir_x, double raydir_y)
{
	int		i;
	int		x;
	double	m;
	double	p_pos[2];

	p_pos[0] = game->player.pos_x * MINIMAP_SIZE;
	p_pos[1] = game->player.pos_y * MINIMAP_SIZE;
	m = raydir_x / raydir_y;
	i = -1;
	while (++i < game->map.height)
	{
		int	top = game->player.map_y * MINIMAP_SIZE;
		int	bottom = (game->player.map_y + 1) * MINIMAP_SIZE;

		x = (int)(m * (i - p_pos[1]) + p_pos[0]);
		if ((raydir_y >= 0 && raydir_x >= 0)
			&& p_pos[1] <= i && i < top)
			game->img.data[i * game->map.width + x] = 0xFFFF00;
		if ((raydir_y >= 0 && raydir_x <= 0)
			&& p_pos[1] <= i && i < top)
			game->img.data[i * game->map.width + x] = 0xFFFF00;
		if ((raydir_y <= 0 && raydir_x >= 0)
			&& bottom <= i && i < p_pos[1])
			game->img.data[i * game->map.width + x] = 0xFFFF00;
		if ((raydir_y <= 0 && raydir_x <= 0)
			&& bottom <= i &&  i < p_pos[1])
			game->img.data[i * game->map.width + x] = 0xFFFF00;
	}
}

void	draw_rays(t_game *game, int	ray_cnt)
{
	int		i;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	i = -1;
	while (++i < ray_cnt)
	{
		camera_x = 2 * i/ (double)ray_cnt - 1;
		raydir_x = game->player.dir_x + game->player.plane_x * camera_x;
		raydir_y = game->player.dir_y + game->player.plane_y * camera_x;
		set_ray(&game->player, camera_x);
		get_dist(game);
		// printf("sideDist_X: %f\tsideDist_Y: %f\n", game->player.sidedist_x, game->player.sidedist_y);
		draw_ray_y(game, raydir_x, raydir_y);
		draw_ray_x(game, raydir_x, raydir_y);
	}
}

void	draw_layer(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.width)
	{
		j = -1;
		while (++j < game->map.height)
		{
			if (j < game->map.height / 2)
				game->img.data[j * game->map.width + i] = game->map.ceiling.color;
			else
				game->img.data[j * game->map.width + i] = game->map.floor.color;
		}
	}
}

int	main_loop(t_game *game)
{
	// draw_layer(game);
	// draw_3d(game);
	draw_rectangles(game);
	draw_lines(game);
	draw_player(game);
	draw_rays(game, 100);
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	game->player.old_time = game->player.time;
	game->player.time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	double	frame_time = (game->player.time - game->player.old_time) / 1000.0;
	game->player.mov_spd = frame_time * 5.0;
	game->player.rot_spd = frame_time * 3.0;

	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	// mlx_destroy_image(game->mlx, game->img.ptr);
	// test_img_init(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	// 0. 매개변수 확인
	if (--argc != 1)
		error_exit("usage : ./cub3D 'map_name.cub'");
	else
		valid_extension(argv[argc]);
	// 1. 게임 세팅
	set_game(&game, argv[argc]);
	game.player.dir_x = 1;
	game.player.plane_y = 0.66;
	// 2. key_handler
	// macOS
	// mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	// mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 0, &close_btn_win, &game);	
	// if Ubuntu
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 1, &close_btn_win, &game);
	// 3. 게임 실행
	// draw_map(&game);
	// execute_game(&game);
	test_img_init(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
