/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:01:46 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 17:46:00 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_elem(t_parser *parser, t_parse_section sect)
{
	int			rst;
	t_element	*temp;

	rst = 0;
	temp = parser->elem_head;
	while (temp)
	{
		if (temp->sect == sect)
			rst |= temp->ident;
		temp = temp->next;
	}
	if (sect == PS_TEXTURE)
		if (rst != (NORTH | SOUTH | WEST | EAST))
			return (1);
	if (sect == PS_LAYER)
		if (rst != (CEILING | FLOOR))
			return (1);
	return (0);
}

t_element	*find_elem(t_element *head, t_identity ident)
{
	while (head)
	{
		if (head->ident == ident)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_img	xpm_to_img(t_game *game, char *file, t_parser *parser)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(game->mlx, file, &img.w, &img.h);
	if (!img.ptr)
		game_error_exit(game, parser, "xpm file not found");
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp,
			&img.size_l, &img.endian);
	return (img);
}

void	img_init(t_game *game)
{
	game->img.ptr = mlx_new_image(game->mlx, game->map.width, game->map.height);
	game->img.data = (int *)mlx_get_data_addr(game->img.ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	game->get_img = 1;
}

void	copy_map(char *map, char *data, int len)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (data[++i])
		map[i] = data[i];
	while (i < len)
		map[i++] = ' ';
	map[i] = '\0';
}
