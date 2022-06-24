/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:08:46 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/24 18:17:59 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minilibx-linux/mlx.h"
#include "../lib/libft/libft.h"
#include "../includes/error.h"
#include "../includes/so_long.h"

t_img	get_xpm_to_img(t_game *game, char *file)
{
	char	*path;
	t_img	img;
	
	path = ft_strjoin("./texture/", file);
	img.ptr = mlx_xpm_file_to_image(game->mlx, path, &img.w, &img.h);
	free(path);
	if (!img.ptr)
		error_exit("init error : xpm to img failed.");
	return (img);
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

void	init_img(t_game *game)
{
	game->imgs.tile = get_xpm_to_img(game, "grass.xpm");
	game->imgs.wall = get_xpm_to_img(game, "tree.xpm");
	game->imgs.exit = get_xpm_to_img(game, "door.xpm");
	game->imgs.player = get_xpm_to_img(game, "kirby.xpm");
	game->imgs.collect = get_xpm_to_img(game, "star.xpm");
	game->imgs.ending = get_xpm_to_img(game, "ending.xpm");
}

void	init_game(t_game *game)
{
	game->map.rows = 0;
	game->map.cols = 0;
	game->map.coord = NULL;
	game->comp.c = 0;
	game->comp.e = 0;
	game->comp.p = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.move = 0;
	game->player.collect = 0;
}

void	set_game(t_game *game, char *file)
{
	init_game(game);
	read_map(game, file);
	init_window(game);
	init_img(game);
}
