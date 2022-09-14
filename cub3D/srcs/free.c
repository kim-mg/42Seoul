#include "../includes/cub3d.h"

void	free_strarr(char **arr)
{
	char	**temp;

	temp = arr;
	while (*temp)
	{
		free(*temp);
		*temp = NULL;
		temp++;
	}
	free(arr);
	arr = NULL;
}

void	free_parser(t_parser *parser)
{
	t_element	*temp;
	t_element	*next;

	if (!parser)
		return ;
	temp = parser->elem_head;
	while (temp)
	{
		next = temp->next;
		free(temp->content);
		temp->content = NULL;
		temp->head = NULL;
		temp->next = NULL;
		free(temp);
		temp = next;
	}
	parser->elem_head = NULL;
	if (parser->map.data)
	{
		free(parser->map.data);
		parser->map.data = NULL;
	}
}

void	free_game(t_game *game)
{
	char	**temp;

	temp = game->map.coord;
	if (game->map.coord)
	{
		while (*temp)
		{
			free(*temp);
			*temp = NULL;
			temp++;
		}
		free(game->map.coord);
		game->map.coord = NULL;
	}
	if (game->texture.get_texture)
	{
		mlx_destroy_image(game->mlx, game->texture.n_wall.ptr);
		mlx_destroy_image(game->mlx, game->texture.s_wall.ptr);
		mlx_destroy_image(game->mlx, game->texture.w_wall.ptr);
		mlx_destroy_image(game->mlx, game->texture.e_wall.ptr);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
}

