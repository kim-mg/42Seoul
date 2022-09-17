/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:18 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 15:29:18 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_lines(t_game *game)
{
	int		i;
	t_map	map;

	map = game->map;
	i = -1;
	while (++i < map.cols * MINI)
		game->img.data[map.rows * MINI * map.width + i] = 0xb3b3b3;
	i = -1;
	while (++i < map.rows * MINI)
		game->img.data[i * map.width + map.cols * MINI] = 0xb3b3b3;
}

void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	s;

	s = MINI;
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

void	draw_map(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
	draw_player(game);
	draw_rays(game, RAY_SIZE);
}
