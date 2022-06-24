/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:16:00 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/23 03:10:29 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/libft/libft.h"
#include "../includes/error.h"
#include "../includes/so_long.h"

int	get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("map read error : file open failed.");
	return (fd);
}

void	check_ext(char *s)
{
	int	i;

	i = ft_strlen(s) - 4;
	if (i < 1 || s[i] != '.')
		error_exit("map read error : file does not have name or extension.");
	if (ft_memcmp(&s[i], ".ber", 4))
		error_exit("map read error : file extension was not '.ber'.");
}

void	get_size_map(t_game *game, int fd)
{
	int		max_cols;
	char	c;

	max_cols = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (game->map.cols < max_cols)
			game->map.cols = max_cols;
		if (c == '\n')
		{
			game->map.rows++;
			max_cols = 0;
		}
		else
			max_cols++;
	}
	if (max_cols)
		game->map.rows++;
}

void	malloc_map(t_game *game, int fd)
{
	int	i;

	get_size_map(game, fd);
	game->map.coord = (char **)malloc(sizeof(char *) * game->map.rows);
	if (!game->map.coord)
		error_exit("map malloc failed.");
	i = -1;
	while (++i < game->map.rows)
	{
		game->map.coord[i] = (char *)malloc(game->map.cols + 1);
		if (!game->map.coord[i])
			error_exit("map malloc failed.");
	}
}

void	read_map(t_game *game, char *filename)
{
	int	fd;

	check_ext(filename);
	fd = get_fd(filename);
	malloc_map(game, fd);
	close(fd);
	fd = get_fd(filename);
	parse_map(game, fd);
	close(fd);
	get_info_comp(game);
}
