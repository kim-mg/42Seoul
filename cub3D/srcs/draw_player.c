#include "../includes/cub3d.h"

void	draw_player_pixels(t_game *game, int x, int y)
{
	int	i;
	int	j;
	double	p_x;
	double	p_y;
	int	s;
	
	s = MINI;
	p_x = (game->player.pos_x - x) * s;
	p_y = (game->player.pos_y - y) * s;
	x *= s;
	y *= s;
	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
			if ((p_y - 4 < i && i < p_y + 4) && (p_x - 4 < j && j < p_x + 4))
				game->img.data[(y + i) * game->map.width + x + j] = 0xFF0000;
	}
}

void	draw_player_all_position(t_game *game, int x, int y)
{
	if (game->map.coord[y - 1][x] != '1')
		draw_player_pixels(game, x, y - 1);
	if (game->map.coord[y + 1][x] != '1')
		draw_player_pixels(game, x, y + 1);
	if (game->map.coord[y][x - 1] != '1')
		draw_player_pixels(game, x - 1, y);
	if (game->map.coord[y][x + 1] != '1')
		draw_player_pixels(game, x + 1, y);
	if (game->map.coord[y - 1][x - 1] != '1')
		draw_player_pixels(game, x - 1, y - 1);
	if (game->map.coord[y + 1][x - 1] != '1')
		draw_player_pixels(game, x - 1, y + 1);
	if (game->map.coord[y - 1][x + 1] != '1')
		draw_player_pixels(game, x + 1, y - 1);
	if (game->map.coord[y + 1][x + 1] != '1')
		draw_player_pixels(game, x + 1, y + 1);
	draw_player_pixels(game, x, y);
}

void	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
			if ((int)game->player.pos_x == j && (int)game->player.pos_y == i)
				draw_player_all_position(game, j, i);
	}
}
