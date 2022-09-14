#include "../includes/cub3d.h"

void	move(t_game *game, double to_x, double to_y)
{
	char	**coord;

	(void)game;
	(void)to_x;
	(void)to_y;
	coord = game->map.coord;
	if (coord[(int)floor(to_y)][(int)floor(to_x)] != '1')
	{
		game->map.coord[(int)floor(game->player.pos_y)][(int)floor(game->player.pos_x)] = '0';
		game->map.coord[(int)floor(to_y)][(int)floor(to_x)] = 'N';
		game->player.pos_x = to_x;
		game->player.pos_y = to_y;
	}
}

int	deal_key(int key_code, t_game *game)
{
	char	**coord = game->map.coord;
	t_player	*p;

	(void)game;
	p = &game->player;
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
	{
		if (coord[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * p->mov_spd)] != '1')
			p->pos_x += p->dir_x * p->mov_spd;
		if (coord[(int)(p->pos_y + p->dir_y * p->mov_spd)][(int)(p->pos_x)] != '1')
			p->pos_y += p->dir_y * p->mov_spd;
	}
	if (key_code == KEY_S)
	{
		if (coord[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x * p->mov_spd)] != '1')
			p->pos_x -= p->dir_x * p->mov_spd;
		if (coord[(int)(p->pos_y - p->dir_y * p->mov_spd)][(int)(p->pos_x)] != '1')
			p->pos_y -= p->dir_y * p->mov_spd;
	}
	if (key_code == KEY_D)
	{
		double	old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_spd) - p->dir_y * sin(p->rot_spd);
		p->dir_y = old_dir_x * sin(p->rot_spd) + p->dir_y * cos(p->rot_spd);
		double	old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(p->rot_spd) - p->plane_y * sin(p->rot_spd);
		p->plane_y = old_plane_x * sin(p->rot_spd) + p->plane_y * cos(p->rot_spd);
	}
	if (key_code == KEY_A)
	{
		double	old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->rot_spd) - p->dir_y * sin(-p->rot_spd);
		p->dir_y = old_dir_x * sin(-p->rot_spd) + p->dir_y * cos(-p->rot_spd);
		double	old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-p->rot_spd) - p->plane_y * sin(-p->rot_spd);
		p->plane_y = old_plane_x * sin(-p->rot_spd) + p->plane_y * cos(-p->rot_spd);
	}
	return (0);
}

int	close_btn_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
