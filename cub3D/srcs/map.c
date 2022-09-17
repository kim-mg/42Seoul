/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:53 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 15:29:54 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_wall(t_map *map, int i, int j)
{
	if ((i == 0 || j == 0 || i == map->rows - 1 || j == map->cols - 1)
		&& map->coord[i][j] == '0')
		return (1);
	if (i != 0 && j != 0 && i != map->rows - 1
		&& j != map->cols - 1 && map->coord[i][j] == ' ')
		if (map->coord[i][j - 1] == '0' || map->coord[i - 1][j] == '0'
			|| map->coord[i][j + 1] == '0' || map->coord[i + 1][j] == '0')
			return (1);
	return (0);
}

int	valid_compo(t_map *map, int i, int j)
{
	char	*chr;

	chr = ft_strchr("NSWE", map->coord[i][j]);
	if (map->sight && chr)
		return (1);
	if (!ft_strchr(" 01NSWE", map->coord[i][j]))
		return (1);
	if ((i == 0 || j == 0 || i == map->rows - 1 || j == map->cols - 1)
		&& chr)
		return (1);
	if (i != 0 && j != 0 && i != map->rows - 1 && j != map->cols - 1
		&& chr)
		if (map->coord[i][j - 1] == ' ' || map->coord[i - 1][j] == ' '
			|| map->coord[i][j + 1] == ' ' || map->coord[i + 1][j] == ' ')
			return (1);
	if (chr && map->sight == 0)
		map->sight = *ft_strchr("NSWE", map->coord[i][j]);
	return (0);
}

int	valid_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->coord[++i])
	{
		j = -1;
		while (map->coord[i][++j])
		{
			if (valid_wall(map, i, j))
				return (1);
			if (valid_compo(map, i, j))
				return (1);
		}
	}
	if (map->sight == 0)
		return (1);
	return (0);
}

char	**mapping(t_map_data *map)
{
	char	**rtn;
	char	**data;
	int		h;

	rtn = (char **)ft_calloc(sizeof(char *), map->height + 1);
	if (!map || !map->data || *map->data == '\0')
		return (NULL);
	h = -1;
	data = ft_split(map->data, '\n');
	while (++h < map->height)
	{
		rtn[h] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!rtn[h] || !data)
		{
			free_strarr(rtn);
			return (NULL);
		}
		copy_map(rtn[h], data[h], map->width - 1);
	}
	free_strarr(data);
	return (rtn);
}

void	set_map(t_parser *parser, t_game *game)
{
	game->map.rows = parser->map.height;
	game->map.cols = parser->map.width;
	game->map.width = WIDTH;
	game->map.height = HEIGHT;
	game->map.coord = mapping(&parser->map);
	if (!game->map.coord)
		game_error_exit(game, parser, "map malloc fail");
	if (valid_map(&game->map))
		game_error_exit(game, parser, "invalid map configuration");
}
