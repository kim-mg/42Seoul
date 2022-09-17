/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:37 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 17:17:42 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_ad(t_game *game)
{
	char		**c;
	t_player	*p;

	c = game->map.coord;
	p = &game->player;
	if (game->key.a)
	{
		if (c[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * p->m_spd)] != '1')
			p->pos_x -= p->plane_x * p->m_spd;
		if (c[(int)(p->pos_y - p->plane_y * p->m_spd)][(int)(p->pos_x)] != '1')
			p->pos_y -= p->plane_y * p->m_spd;
	}
	else if (game->key.d)
	{
		if (c[(int)(p->pos_y)][(int)(p->pos_x + p->plane_x * p->m_spd)] != '1')
			p->pos_x += p->plane_x * p->m_spd;
		if (c[(int)(p->pos_y + p->plane_y * p->m_spd)][(int)(p->pos_x)] != '1')
			p->pos_y += p->plane_y * p->m_spd;
	}
}

void	move_player_ws(t_game *game)
{
	char		**c;
	t_player	*p;

	c = game->map.coord;
	p = &game->player;
	if (game->key.w)
	{
		if (c[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * p->m_spd)] != '1')
			p->pos_x += p->dir_x * p->m_spd;
		if (c[(int)(p->pos_y + p->dir_y * p->m_spd)][(int)(p->pos_x)] != '1')
			p->pos_y += p->dir_y * p->m_spd;
	}
	else if (game->key.s)
	{
		if (c[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x * p->m_spd)] != '1')
			p->pos_x -= p->dir_x * p->m_spd;
		if (c[(int)(p->pos_y - p->dir_y * p->m_spd)][(int)(p->pos_x)] != '1')
			p->pos_y -= p->dir_y * p->m_spd;
	}
}

void	rotate_player(t_game *game)
{
	t_player	*p;
	double		dir_x;
	double		plane_x;

	p = &game->player;
	if (game->key.r)
	{
		dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->r_spd) - p->dir_y * sin(p->r_spd);
		p->dir_y = dir_x * sin(p->r_spd) + p->dir_y * cos(p->r_spd);
		plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(p->r_spd)
			- p->plane_y * sin(p->r_spd);
		p->plane_y = plane_x * sin(p->r_spd) + p->plane_y * cos(p->r_spd);
	}
	else if (game->key.l)
	{
		dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->r_spd) - p->dir_y * sin(-p->r_spd);
		p->dir_y = dir_x * sin(-p->r_spd) + p->dir_y * cos(-p->r_spd);
		plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-p->r_spd)
			- p->plane_y * sin(-p->r_spd);
		p->plane_y = plane_x * sin(-p->r_spd) + p->plane_y * cos(-p->r_spd);
	}
}

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		game->key.w = 1;
	if (key_code == KEY_A)
		game->key.a = 1;
	if (key_code == KEY_S)
		game->key.s = 1;
	if (key_code == KEY_D)
		game->key.d = 1;
	if (key_code == KEY_AR_L)
		game->key.l = 1;
	if (key_code == KEY_AR_R)
		game->key.r = 1;
	return (0);
}

int	release_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		game->key.w = 0;
	if (key_code == KEY_A)
		game->key.a = 0;
	if (key_code == KEY_S)
		game->key.s = 0;
	if (key_code == KEY_D)
		game->key.d = 0;
	if (key_code == KEY_AR_L)
		game->key.l = 0;
	if (key_code == KEY_AR_R)
		game->key.r = 0;
	return (0);
}
