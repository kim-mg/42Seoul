/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:14:57 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/14 21:21:06 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"
#include "../includes/so_long.h"

int	check_comp(t_game *game)
{
	if (game->comp.c < 1)
		return (0);
	if (game->comp.e != 1)
		return (0);
	if (game->comp.p != 1)
		return (0);
	return (1);
}

void	get_info_comp(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->TILE.rows)
	{
		j = -1;
		while (++j < game->TILE.cols)
		{
			if (game->TILE.coord[i][j] == 'C')
				game->comp.c++;
			if (game->TILE.coord[i][j] == 'E')
				game->comp.e++;
			if (game->TILE.coord[i][j] == 'P')
			{
				game->player.x = i;
				game->player.y = j;
				game->comp.p++;
			}
		}
	}
	if (!check_comp(game))
		error_exit("invalid comp : necessary components do not satisfied.");
}
