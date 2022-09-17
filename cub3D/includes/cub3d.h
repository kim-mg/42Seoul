/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:27:02 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 18:27:25 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
// #include "../minilibx-linux/mlx.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_DESTROY_NOTIFY	17

# define WIDTH		1320
# define HEIGHT		560
# define MINI		40
# define RAY_SIZE	100

enum e_key_setting
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_AR_L = 123,
	KEY_AR_R = 124,
	KEY_AR_U = 126,
	KEY_AR_D = 125,
};

// enum e_ubuntu_key
// {
// 	KEY_ESC = 0xff1b,
// 	KEY_W = 0x77,
// 	KEY_A = 0x61,
// 	KEY_S = 0x73,
// 	KEY_D = 0x64,
// };

typedef enum e_identity
{
	NORTH = 1 << 0,
	SOUTH = 1 << 1,
	WEST = 1 << 2,
	EAST = 1 << 3,
	CEILING = 1 << 4,
	FLOOR = 1 << 5,
}	t_identity;

typedef enum e_parse_section
{
	PS_TEXTURE,
	PS_LAYER,
	PS_MAP,
	PS_NOTMAP,
	PS_DONE,
}	t_parse_section;

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
}	t_map_data;

typedef struct s_parser
{
	int			fd;
	char		*line;
	int			sect;
	int			sect_cnt;
	int			elem_cnt;
	t_element	*elem_head;
	t_map_data	map;
}	t_parser;

typedef struct s_layer
{
	int	color;
}	t_layer;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		w;
	int		h;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_texture
{
	int		get_texture;
	int		getin;
	t_img	n_wall;
	t_img	s_wall;
	t_img	w_wall;
	t_img	e_wall;
}	t_texture;

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
}	t_map;

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
	double	m_spd;
	double	r_spd;
	double	time;
	double	old_time;
}	t_player;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	r;
	int	l;
}	t_key;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			get_img;
	t_texture	texture;
	t_map		map;
	t_player	player;
	t_img		img;
	t_key		key;
}	t_game;

//draw_3d.c
void		draw_3d(t_game *game);
void		set_ray(t_player *p, double camera_x);
double		get_dist(t_game *game);

// draw_map.c
void		draw_map(t_game *game);

// draw_player.c
void		draw_player(t_game *game);

// draw_rays.c
void		draw_rays(t_game *game, int ray_cnt);

// free.c
void		free_game(t_game *game);
void		free_images(t_game *game);
void		free_parser(t_parser *parser);
void		free_strarr(char **arr);

// init.c
int			set_window(t_game *game);
void		init_game(t_game *game);
void		init_key(t_game *game);
void		parser_init(t_parser *parser);

// key.c
int			deal_key(int key_code, t_game *game);
int			release_key(int key_code, t_game *game);
void		move_player_ad(t_game *game);
void		move_player_ws(t_game *game);
void		rotate_player(t_game *game);

// layer.c
void		draw_layer(t_game *game, t_map *map);
void		set_layer(t_parser *parser, t_game *game, t_map *map);

// map.c
void		set_map(t_parser *parser, t_game *game);

// error.c
void		error_exit(char *err);
void		game_error_exit(t_game *game, t_parser *parser, char *err);
void		parse_error_exit(t_parser *parser, char *err);

// parsing_util.c
t_element	*new_elem(t_element *head, char *cont,
				t_parse_section sect, t_identity ident);
void		add_elem(t_element **e_head, char *cont,
				t_parse_section sect, t_identity ident);
char		**pre_proc_elem(char *line);

// parsing.c
int			get_elem(t_parser *parser, char *line);
void		check_section(t_parser *parser);
void		get_map_data(t_parser *parser, char *line);
void		parse_cub(t_parser *parser, char *cub);

// texture.c
void		draw_texture(t_game *game, int x, t_img *wall, double dist);

// set_game.c
void		set_game(t_game *game, char *data);

// util.c
int			valid_elem(t_parser *parser, t_parse_section sect);
t_element	*find_elem(t_element *head, t_identity ident);
t_img		xpm_to_img(t_game *game, char *file, t_parser *parser);
void		img_init(t_game *game);
void		copy_map(char *map, char *data, int len);

//window.c
int			close_btn_win(t_game *game);

#endif