/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:14:01 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/25 16:51:28 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../includes/error.h"
#include "../includes/so_long.h"

int	valid_rectangle(t_game *game, char *line)
{
	int	l;

	l = ft_strlen(line);
	if (l > game->map.cols && line[game->map.cols] == '\n')
		l--;
	if (game->map.cols != l)
		return (0);
	return (1);
}

int	valid_component(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E'
		|| c == 'P' || c == 'M')
		return (1);
	return (0);
}

int	valid_wall(t_game *game)
{
	char	**coord;
	int		i;

	coord = game->map.coord;
	i = -1;
	while (++i < game->map.rows)
		if (coord[i][0] != '1' || coord[i][game->map.cols-1] != '1')
			return (0);
	i = -1;
	while (++i < game->map.cols)
		if (coord[0][i] != '1' || coord[game->map.rows-1][i] != '1')
			return (0);
	return (1);
}

void	parse_map(t_game *game, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!valid_rectangle(game, line))
			error_exit("invalid map : not rectangle.");
		j = -1;
		while (++j < game->map.cols)
		{
			if (!valid_component(line[j]))
				error_exit("invalid map : components.");
			else
				game->map.coord[i][j] = line[j];
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (!valid_wall(game))
		error_exit("invalid map : not walled.");
}
