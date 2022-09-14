/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:17:33 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/14 21:21:06 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../includes/so_long.h"

int	ending_key(int key_code)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

void	clear_game(t_game *game)
{
	int	w;
	int	h;

	w = game->imgs.ending.w;
	h = game->imgs.ending.h;
	mlx_destroy_window(game->mlx, game->win);
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	put_img(game, game->imgs.ending.ptr, 0, 0);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &ending_key, &game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &win_close, &game);
}

void	move(t_game *game, int to_x, int to_y)
{
	char	**coord;

	coord = game->TILE.coord;
	if (coord[to_x][to_y] == 'C')
		game->player.collect++;
	if (coord[to_x][to_y] == 'E' && game->player.collect == game->comp.c)
		clear_game(game);
	if (coord[to_x][to_y] != '1' && coord[to_x][to_y] != 'E' )
	{
		game->TILE.coord[game->player.x][game->player.y] = '0';
		game->TILE.coord[to_x][to_y] = 'P';
		game->player.x = to_x;
		game->player.y = to_y;
		game->player.move++;
		ft_printf("move : %d\n", game->player.move);
		draw_map(game);
	}
}
