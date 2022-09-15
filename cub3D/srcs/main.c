#include "../includes/cub3d.h"
#include <stdio.h>

void	valid_extension(const char *cub)
{
	char	*temp;

	temp = ft_strnstr(cub, ".cub", ft_strlen(cub));
	if (!temp || (temp && ft_strncmp(temp, ".cub", ft_strlen(temp) + 1)))
		error_exit("invalid extension");
}

// void drawLetter(unsigned char n, int x, int y, const int color, bool bg, const int color2)
// {
//   int u,v;

//   for (v = 0; v < 8; v++)
//   for (u = 0; u < 8; u++)
//   {
//     if(font[n][u][v]) pset(x + u, y + v, color);
//     else if(bg) pset(x + u, y + v, color2);
//   }
// }

// //Draws a string of text
// int printString(const char *text, int x, int y, const int color, bool bg, const int color2, int forceLength)
// {
//   int amount = 0;
//   for(size_t i = 0; i < ft_strlen(text); i++)
//   {
//     amount++;
//     drawLetter(text[i], x, y, color, bg, color2);
//     x += 8;
//     if(x > w - 8) {x %= 8; y += 8;}
//     if(y > h - 8) {y %= 8;}
//   }
//   while(amount < forceLength)
//   {
//     amount++;
//     drawLetter(' ', x, y, color, bg, color2);
//     x += 8;
//     if(x > w - 8) {x %= 8; y += 8;}
//     if(y > h - 8) {y %= 8;}
//   }
//   return h * x + y;
// }

// int print(const int val, int x = 0, int y = 0, const int color = 0xFFFFFF, bool bg = 0, const int color2 = 0x000000, int forceLength = 0)
// {
// 	char *text = ft_itoa(val);
//   	return printString(text, x, y, color, bg, color2, forceLength);
// }

void	set_frame(t_game *game)
{
	struct timeval	tv;
	double			frame_time;

	gettimeofday(&tv, NULL);
	game->player.old_time = game->player.time;
	game->player.time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	frame_time = (game->player.time - game->player.old_time) / 1000.0;
	// print(1.0 / frame_time);
	// printf("fps counter: %f\n", 1.0 / frame_time);
	game->player.mov_spd = frame_time * 5.0;
	game->player.rot_spd = frame_time * 3.0;
	// printf("f_t: %f\tmvspd: %f\trotspd: %f\n", frame_time, game->player.mov_spd, game->player.rot_spd);

	// 굳이 저 위의 것으로 써야하나 싶어서 고정 값으로 줘볼 생각
	// game->player.mov_spd = 0.1;
	// game->player.rot_spd = 0.1;
}

int	main_loop(t_game *game)
{
	draw_layer(game, &game->map);
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
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
