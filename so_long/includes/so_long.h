/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:11:45 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/24 18:22:02 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC	0xff1b
# define KEY_W	0x77
# define KEY_A	0x61
# define KEY_S	0x73
# define KEY_D	0x64

# define TILE_SIZE	64

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		w;
	int		h;
}			t_img;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coord;
}			t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	move;
	int	collect;
}			t_player;

typedef struct s_comp
{
	int		c;
	int		e;
	int		p;
}			t_comp;

typedef struct s_imgs
{
	t_img	tile;
	t_img	wall;
	t_img	collect;
	t_img	exit;
	t_img	player;
	t_img	ending;
}			t_imgs;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_imgs		imgs;
	t_map		map;
	t_player	player;
	t_comp		comp;
}			t_game;

void	put_img(t_game *game, t_img *ptr, int i, int j);
void	draw_map(t_game *game);

void	read_map(t_game *game, char *filename);

void	parse_map(t_game *game, int fd);

void	get_info_comp(t_game *game);

void	set_game(t_game *game, char *file);

void	move(t_game *game, int to_x, int to_y);

int	win_close(t_game *game);
#endif
