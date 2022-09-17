/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:31 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 17:45:39 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parser_init(t_parser *parser)
{
	parser->fd = 0;
	parser->sect = PS_NOTMAP;
	parser->sect_cnt = 0;
	parser->line = "";
	parser->elem_cnt = 1;
	parser->elem_head = NULL;
	parser->map.width = 0;
	parser->map.height = 0;
	parser->map.data = NULL;
}

void	init_key(t_game *game)
{
	game->key.a = 0;
	game->key.d = 0;
	game->key.s = 0;
	game->key.w = 0;
	game->key.l = 0;
	game->key.r = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->get_img = 0;
	game->map.cols = 0;
	game->map.rows = 0;
	game->map.coord = NULL;
	game->map.sight = 0;
	game->map.ceiling.color = 0;
	game->map.floor.color = 0;
	game->player.pos_x = 0;
	game->player.pos_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->player.m_spd = 0;
	game->player.r_spd = 0;
	game->player.time = 0;
	game->player.old_time = 0;
	game->texture.get_texture = 0;
	game->texture.getin = 0;
}

int	set_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	width = game->map.width;
	height = game->map.height;
	game->win = mlx_new_window(game->mlx, width, height, "cub3D");
	if (!game->win)
		return (1);
	return (0);
}
