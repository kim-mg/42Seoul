#include "../includes/cub3d.h"

void	move_player(int key_code, t_game *game)
{
	char		**c;
	t_player	*p;

	c = game->map.coord;
	p = &game->player;
	if (key_code == KEY_W)
	{
		if (c[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * p->mov_spd)] != '1')
			p->pos_x += p->dir_x * p->mov_spd;
		if (c[(int)(p->pos_y + p->dir_y * p->mov_spd)][(int)(p->pos_x)] != '1')
			p->pos_y += p->dir_y * p->mov_spd;
	}
	if (key_code == KEY_S)
	{
		if (c[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x * p->mov_spd)] != '1')
			p->pos_x -= p->dir_x * p->mov_spd;
		if (c[(int)(p->pos_y - p->dir_y * p->mov_spd)][(int)(p->pos_x)] != '1')
			p->pos_y -= p->dir_y * p->mov_spd;
	}
}

void	rotate_player(int key_code, t_game *game)
{
	t_player	*p;
	double		dir_x;
	double		plane_x;

	p = &game->player;
	if (key_code == KEY_D)
	{
		dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_spd) - p->dir_y * sin(p->rot_spd);
		p->dir_y = dir_x * sin(p->rot_spd) + p->dir_y * cos(p->rot_spd);
		plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(p->rot_spd)
			- p->plane_y * sin(p->rot_spd);
		p->plane_y = plane_x * sin(p->rot_spd) + p->plane_y * cos(p->rot_spd);
	}
	if (key_code == KEY_A)
	{
		dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->rot_spd) - p->dir_y * sin(-p->rot_spd);
		p->dir_y = dir_x * sin(-p->rot_spd) + p->dir_y * cos(-p->rot_spd);
		plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-p->rot_spd)
			- p->plane_y * sin(-p->rot_spd);
		p->plane_y = plane_x * sin(-p->rot_spd) + p->plane_y * cos(-p->rot_spd);
	}
}

int	deal_key(int key_code, t_game *game)
{
	char		**c;
	t_player	*p;

	c = game->map.coord;
	p = &game->player;
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W || key_code == KEY_S)
		move_player(key_code, game);
	if (key_code == KEY_D || key_code == KEY_A)
		rotate_player(key_code, game);
	return (0);
}

int	close_btn_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
