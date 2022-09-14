#include "../includes/cub3d.h"

void	draw_quad_pos(t_game *game, int x, int y, int quadrant)
{
	t_player	*p;

	p = &game->player;
	if (quadrant == 1)
	{
		if (p->side && x < (p->map_x + 1) * MINI && y < p->map_y * MINI)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
		if (!p->side && x < p->map_x * MINI && y < (p->map_y + 1) * MINI)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
	}
	if (quadrant == 2)
	{
		if (p->side && p->map_x * MINI <= x && y < p->map_y * MINI)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
		if (!p->side && (p->map_x + 1) * MINI <= x && y < (p->map_y + 1) * MINI)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
	}
}

void	draw_quad_neg(t_game *game, int x, int y, int quadrant)
{
	t_player	*p;

	p = &game->player;
	if (quadrant == 3)
	{
		if (p->side && p->map_x * MINI <= x && (p->map_y + 1) * MINI <= y)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
		if (!p->side && (p->map_x + 1) * MINI <= x && p->map_y * MINI <= y)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
	}
	if (quadrant == 4)
	{
		if (p->side && x < (p->map_x + 1) * MINI && (p->map_y + 1) * MINI <= y)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
		if (!p->side && x < p->map_x * MINI && p->map_y * MINI <= y)
				game->img.data[y * game->map.width + x] = 0xFFFF00;
	}
}

void	draw_ray_y(t_game *game, double raydir_x, double raydir_y)
{
	int		i;
	int		y;
	double	m;
	double	p_pos[2];

	p_pos[0] = game->player.pos_x * MINI;
	p_pos[1] = game->player.pos_y * MINI;
	m = raydir_y / raydir_x;
	i = -1;
	while (++i < game->map.width)
	{
		y = (int)(m * (i - p_pos[0]) + p_pos[1]);
		if ((raydir_x > 0 && raydir_y > 0) && p_pos[0] <= i)
			draw_quad_pos(game, i, y, 1);
		if ((raydir_x < 0 && raydir_y > 0) && i < p_pos[0])
			draw_quad_pos(game, i, y, 2);
		if ((raydir_x < 0 && raydir_y < 0) && i < p_pos[0])
			draw_quad_neg(game, i, y, 3);
		if ((raydir_x > 0 && raydir_y < 0) && p_pos[0] <= i)
			draw_quad_neg(game, i, y, 4);
	}
}

void	draw_ray_x(t_game *game, double raydir_x, double raydir_y)
{
	int		i;
	int		x;
	double	m;
	double	p_pos[2];

	p_pos[0] = game->player.pos_x * MINI;
	p_pos[1] = game->player.pos_y * MINI;
	m = raydir_x / raydir_y;
	i = -1;
	while (++i < game->map.height)
	{
		x = (int)(m * (i - p_pos[1]) + p_pos[0]);
		if ((raydir_y > 0 && raydir_x > 0) && p_pos[1] <= i)
			draw_quad_pos(game, x, i, 1);
		if ((raydir_y > 0 && raydir_x < 0) && p_pos[1] <= i)
			draw_quad_pos(game, x, i, 2);
		if ((raydir_y < 0 && raydir_x < 0) && i < p_pos[1])
			draw_quad_neg(game, x, i, 3);
		if ((raydir_y < 0 && raydir_x > 0) && i < p_pos[1])
			draw_quad_neg(game, x, i, 4);
	}
}

void	draw_rays(t_game *game, int	ray_cnt)
{
	int		i;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	i = -1;
	while (++i < ray_cnt)
	{
		camera_x = 2 * i/ (double)ray_cnt - 1;
		raydir_x = game->player.dir_x + game->player.plane_x * camera_x;
		raydir_y = game->player.dir_y + game->player.plane_y * camera_x;
		set_ray(&game->player, camera_x);
		get_dist(game);
		draw_ray_y(game, raydir_x, raydir_y);
		draw_ray_x(game, raydir_x, raydir_y);
	}
}
