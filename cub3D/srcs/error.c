#include "../includes/cub3d.h"

void	error_exit(char *err)
{
	size_t	size;

	size = ft_strlen(err);
	write(2, "Error\n", 6);
	write(2, err, size);
	write(2, "\n", 1);
	exit(1);
}

void	game_error_exit(t_game *game, t_parser *parser, char *err)
{
	free_parser(parser);
	free_game(game);
	error_exit(err);
}

void	parse_error_exit(t_parser *parser, char *err)
{
	free_parser(parser);
	error_exit(err);
}
