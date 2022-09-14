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

	gettimeofday(&tv, NULL);
	game->player.old_time = game->player.time;
	game->player.time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	double	frame_time = (game->player.time - game->player.old_time) / 1000.0;
	game->player.mov_spd = frame_time * 5.0;
	game->player.rot_spd = frame_time * 3.0;
}

int	main_loop(t_game *game)
{
	draw_layer(game);
	draw_3d(game);
	draw_map(game);
	set_frame(game);
	
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
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
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 1, &close_btn_win, &game);
	img_init(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
