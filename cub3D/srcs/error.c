/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:29:27 by myunkim           #+#    #+#             */
/*   Updated: 2022/09/17 16:48:02 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
	free_images(game);
	free_game(game);
	error_exit(err);
}

void	parse_error_exit(t_parser *parser, char *err)
{
	free_parser(parser);
	error_exit(err);
}
