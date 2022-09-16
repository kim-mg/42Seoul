#include "../includes/cub3d.h"

double	get_wall_x(t_game *game, double dist)
{
	double	tmp;

	if (!game->player.side)
		tmp = dist * game->player.raydir_y + game->player.pos_y;
	else
		tmp = dist * game->player.raydir_x + game->player.pos_x;
	return (tmp - floor(tmp));
}

int	get_color(t_game *g, t_img *wall, double pos, double dist)
{
	int	x;
	int	y;

	x = (int)(get_wall_x(g, dist) * (double)wall->w);
	if ((!g->player.side && g->player.raydir_x > 0)
		|| (g->player.side && g->player.raydir_y > 0))
		x = wall->w - x - 1;
	y = (int)pos & (wall->h - 1);
	return (wall->data[y * wall->w + x]);
}

void	draw_texture(t_game *game, int x, t_img *wall, double dist)
{
	double	pos;
	double	step;
	int		line_h;
	int		top;
	int		bottom;

	line_h = (int)(game->map.height / dist);
	step = (double)wall->h / (double)line_h;
	top = (int)((game->map.height - line_h) / 2);
	if (top < 0)
		top = 0;
	bottom = (int)((game->map.height + line_h) / 2);
	if (bottom >= game->map.height)
		bottom = game->map.height - 1;
	pos = (top - game->map.height / 2 + line_h / 2) * step;
	while (top <= bottom)
	{
		pos += step;
		game->img.data[top * game->map.width + x]
			= get_color(game, wall, pos, dist);
		top++;
	}
}
