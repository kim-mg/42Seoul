/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:45:25 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/01 21:30:05 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// #include "../mlx/mlx.h"
#include "../minilibx-linux/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../includes/error.h"
#include "../includes/so_long.h"

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move(game, game->player.x - 1, game->player.y);
	if (key_code == KEY_A)
		move(game, game->player.x, game->player.y - 1);
	if (key_code == KEY_S)
		move(game, game->player.x + 1, game->player.y);
	if (key_code == KEY_D)
		move(game, game->player.x, game->player.y + 1);
	return (0);
}

int	win_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (--argc < 1)
		error_exit("main error : need execute with map file.");
	set_game(&game, argv[argc]);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &win_close, &game);
	draw_map(&game);
	mlx_loop(game.mlx);
}
