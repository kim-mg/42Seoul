/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:41 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 15:35:37 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_rgb(char **rgb)
{
	char	**temp;
	int		i;

	temp = rgb;
	while (*temp)
	{
		i = -1;
		while (*((*temp) + ++i))
			if (!ft_isdigit(*((*temp) + i)))
				return (1);
		if (ft_atoi(*temp) < 0 || 255 < ft_atoi(*temp))
			return (1);
		++temp;
	}
	if (temp - rgb < 3)
		return (1);
	return (0);
}

int	to_rgb(char *data)
{
	int		rtn;
	char	**rgb;
	char	*temp;
	int		cnt;

	rtn = 0;
	rgb = ft_split(data, ',');
	temp = data;
	cnt = 0;
	while (*temp)
		if (*temp++ == ',')
			++cnt;
	if (check_rgb(rgb) || cnt > 3)
	{
		free_strarr(rgb);
		return (-1);
	}
	rtn = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_strarr(rgb);
	return (rtn);
}

void	set_layer(t_parser *parser, t_game *game, t_map *map)
{
	char	*color;

	if (valid_elem(parser, PS_LAYER))
		game_error_exit(game, parser, "texture element unsatisfied");
	color = find_elem(parser->elem_head, CEILING)->content;
	if (*color == '\0')
		game_error_exit(game, parser, "invalid floor and ceiling color");
	map->ceiling.color = to_rgb(color);
	color = find_elem(parser->elem_head, FLOOR)->content;
	if (*color == '\0')
		game_error_exit(game, parser, "invalid floor and ceiling color");
	map->floor.color = to_rgb(color);
	if (map->ceiling.color == -1 || map->floor.color == -1)
		game_error_exit(game, parser, "invalid floor and ceiling color");
}

void	draw_layer(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			if (j < map->height / 2)
				game->img.data[j * map->width + i] = map->ceiling.color;
			else
				game->img.data[j * map->width + i] = map->floor.color;
		}
	}
}
