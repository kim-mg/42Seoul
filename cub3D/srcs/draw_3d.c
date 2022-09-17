/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:14 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 15:29:16 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_deltadist(t_player *p)
{
	if (!p->raydir_x)
		p->deltadist_x = 1e30;
	else
		p->deltadist_x = fabs(1 / p->raydir_x);
	if (!p->raydir_y)
		p->deltadist_y = 1e30;
	else
		p->deltadist_y = fabs(1 / p->raydir_y);
}

void	set_sidedist(t_player *p)
{
	if (p->raydir_x < 0)
	{
		p->step_x = -1;
		p->sidedist_x = (p->pos_x - (int)p->pos_x) * p->deltadist_x;
	}
	else
	{
		p->step_x = 1;
		p->sidedist_x = ((int)p->pos_x - p->pos_x + 1.0) * p->deltadist_x;
	}
	if (p->raydir_y < 0)
	{
		p->step_y = -1;
		p->sidedist_y = (p->pos_y - (int)p->pos_y) * p->deltadist_y;
	}
	else
	{
		p->step_y = 1;
		p->sidedist_y = ((int)p->pos_y - p->pos_y + 1.0) * p->deltadist_y;
	}
}

void	set_ray(t_player *p, double camera_x)
{
	p->map_x = (int)p->pos_x;
	p->map_y = (int)p->pos_y;
	p->raydir_x = p->dir_x + p->plane_x * camera_x;
	p->raydir_y = p->dir_y + p->plane_y * camera_x;
	set_deltadist(p);
	set_sidedist(p);
}

double	get_dist(t_game *game)
{
	while (1)
	{
		if (game->player.sidedist_x < game->player.sidedist_y)
		{
			game->player.sidedist_x += game->player.deltadist_x;
			game->player.map_x += game->player.step_x;
			game->player.side = 0;
		}
		else
		{
			game->player.sidedist_y += game->player.deltadist_y;
			game->player.map_y += game->player.step_y;
			game->player.side = 1;
		}
		if (game->map.coord[game->player.map_y][game->player.map_x] == '1')
			break ;
	}
	if (!game->player.side)
		return (game->player.sidedist_x - game->player.deltadist_x);
	else
		return (game->player.sidedist_y - game->player.deltadist_y);
}

void	draw_3d(t_game *game)
{
	int		w;
	double	camera_x;
	double	perp_wall_dist;
	t_img	wall;

	w = -1;
	while (++w < game->map.width)
	{
		camera_x = 2 * w / (double)game->map.width - 1;
		set_ray(&game->player, camera_x);
		perp_wall_dist = get_dist(game);
		if (!game->player.side && game->player.raydir_x >= 0)
			wall = game->texture.w_wall;
		else if (!game->player.side && game->player.raydir_x < 0)
			wall = game->texture.e_wall;
		else if (game->player.side && game->player.raydir_y >= 0)
			wall = game->texture.n_wall;
		else if (game->player.side && game->player.raydir_y < 0)
			wall = game->texture.s_wall;
		draw_texture(game, w, &wall, perp_wall_dist);
	}
}
