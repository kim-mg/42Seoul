/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:44 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 17:17:15 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	valid_extension(const char *cub)
{
	char	*temp;

	temp = ft_strnstr(cub, ".cub", ft_strlen(cub));
	if (!temp || (temp && ft_strncmp(temp, ".cub", ft_strlen(temp) + 1)))
		error_exit("invalid extension");
}

void	set_frame(t_game *game)
{
	struct timeval	tv;
	double			frame_time;

	gettimeofday(&tv, NULL);
	game->player.old_time = game->player.time;
	game->player.time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	frame_time = (game->player.time - game->player.old_time) / 1000.0;
	game->player.m_spd = frame_time * 3.0;
	game->player.r_spd = frame_time * 2.0;
}

void	update_key(t_game *game)
{
	t_key	*k;

	k = &game->key;
	if (k->a || k->d)
		move_player_ad(game);
	if (k->w || k->s)
		move_player_ws(game);
	if (k->r || k->l)
		rotate_player(game);
}

int	main_loop(t_game *game)
{
	draw_layer(game, &game->map);
	draw_3d(game);
	draw_map(game);
	set_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	update_key(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (--argc != 1)
		error_exit("usage : ./cub3D 'map_name.cub'");
	else
		valid_extension(argv[argc]);
	set_game(&game, argv[argc]);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &release_key, &game);
	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 0, &close_btn_win, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
