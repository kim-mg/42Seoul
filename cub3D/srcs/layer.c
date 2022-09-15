#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	to_rgb(char *data)
{
	int		rtn;
	char	**rgb;

	rtn = 0;
	rgb = ft_split(data, ',');
	rtn = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_strarr(rgb);
	return (rtn);
}

void	set_layer(t_parser *parser, t_game *game, t_map *map)
{
	if (valid_elem(parser, PS_LAYER))
		game_error_exit(game, parser, "texture element unsatisfied");
	map->ceiling.color = to_rgb(find_elem(parser->elem_head, CEILING)->content);
	map->floor.color = to_rgb(find_elem(parser->elem_head, FLOOR)->content);
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
