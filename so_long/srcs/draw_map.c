/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:16:22 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/14 21:21:06 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"

void	put_img(t_game *game, t_img *ptr, int i, int j)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, ptr, j * TILE_SIZE, i * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->TILE.rows)
	{
		j = 0;
		while (j < game->TILE.cols)
		{
			if (game->TILE.coord[i][j] == '1')
				put_img(game, game->imgs.wall.ptr, i, j);
			else if (game->TILE.coord[i][j] == 'C')
				put_img(game, game->imgs.collect.ptr, i, j);
			else if (game->TILE.coord[i][j] == 'P')
				put_img(game, game->imgs.player.ptr, i, j);
			else if (game->TILE.coord[i][j] == 'E')
				put_img(game, game->imgs.exit.ptr, i, j);
			else
				put_img(game, game->imgs.tile.ptr, i, j);
			j++;
		}
		i++;
	}
}
