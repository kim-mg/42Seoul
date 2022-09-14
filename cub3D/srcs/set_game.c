#include "../includes/cub3d.h"

void	set_player_dir(t_game *game, char *sight)
{
	if (*sight == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	if (*sight == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
	if (*sight == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -0.66;
	}
	if (*sight == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = 0.66;
	}
}

void	set_player(t_game *game)
{
	int		i;
	int		j;
	char	*sight;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			sight = ft_strchr("NSWE", game->map.coord[i][j]);
			if (sight)
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				set_player_dir(game, sight);
			}
		}
	}
}

void	set_texture(t_parser *parser, t_game *game)
{
	t_element	*elem;

	if (valid_elem(parser, PS_TEXTURE))
		game_error_exit(game, parser, "texture element unsatisfied");
	elem = find_elem(parser->elem_head, ID_NORTH);
	game->texture.n_wall = xpm_to_img(game, elem->content, parser);
	elem = find_elem(parser->elem_head, ID_SOUTH);
	game->texture.s_wall = xpm_to_img(game, elem->content, parser);
	elem = find_elem(parser->elem_head, ID_WEST);
	game->texture.w_wall = xpm_to_img(game, elem->content, parser);
	elem = find_elem(parser->elem_head, ID_EAST);
	game->texture.e_wall = xpm_to_img(game, elem->content, parser);
	game->texture.get_texture = 1;
}

void	set_game(t_game *game, char *data)
{
	t_parser	parser;

	init_game(game);
	parse_cub(&parser, data);
	set_map(&parser, game);
	if (set_window(game))
		game_error_exit(game, &parser, "mlx or window init failed");
	set_texture(&parser, game);
	set_layer(&parser, game);
	set_player(game);
	img_init(game);
	free_parser(&parser);
}
