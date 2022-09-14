#include "../includes/cub3d.h"

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY));
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[(int)floor(y1) * game->map.width + (int)floor(x1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_game *game)
{
	int	i;
	int	j;
	int	s;

	s = MINI;
	i = -1;
	while (++i < game->map.cols)
		draw_line(game, i * s, 0, i * s, game->map.rows * s);
	draw_line(game, game->map.cols * s - 1, 0, game->map.cols * s - 1, game->map.rows * s);
	j = -1;
	while (++j < game->map.rows)
		draw_line(game, 0, j * s, game->map.cols * s, j * s);
	draw_line(game, 0, game->map.rows * s - 1, game->map.cols * s, game->map.rows * s - 1);
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
	draw_rays(game, 100);
}
