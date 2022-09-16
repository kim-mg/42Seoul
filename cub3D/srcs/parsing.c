#include <fcntl.h>
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../includes/cub3d.h"

int	get_elem(t_parser *parser, char *line)
{
	char	**split;

	split = pre_proc_elem(line);
	if (!split)
		return (1);
	if (!ft_strncmp(split[0], "NO", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, NORTH);
	else if (!ft_strncmp(split[0], "SO", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, SOUTH);
	else if (!ft_strncmp(split[0], "WE", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, WEST);
	else if (!ft_strncmp(split[0], "EA", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, EAST);
	else if (!ft_strncmp(split[0], "F", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_LAYER, FLOOR);
	else if (!ft_strncmp(split[0], "C", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_LAYER, CEILING);
	else
	{
		free_strarr(split);
		return (1);
	}
	parser->elem_cnt++;
	free_strarr(split);
	return (0);
}

void	check_section(t_parser *parser)
{
	if (!parser->line)
		parser->sect = PS_DONE;
	if (parser->sect_cnt == 2 && parser->line)
	{
		while (*parser->line == '\n')
		{
			free(parser->line);
			parser->line = get_next_line(parser->fd);
		}
		parser->sect = PS_MAP;
	}
	if (parser->sect == PS_NOTMAP)
	{
		while (*parser->line == '\n')
		{
			free(parser->line);
			parser->line = get_next_line(parser->fd);
		}
		if (parser->elem_cnt >= 6)
			parser->sect_cnt = 2;
	}
}

void	get_map_data(t_parser *parser, char *line)
{
	int		len;
	char	*new;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len -= 1;
	new = NULL;
	if (*line == '\n')
		parse_error_exit(parser, "map has empty line");
	if (parser->map.width == 0 || len > parser->map.width)
		parser->map.width = len;
	if (!parser->map.data)
		parser->map.data = ft_strdup(line);
	else
	{
		new = ft_strjoin(parser->map.data, line);
		free(parser->map.data);
		parser->map.data = new;
	}
	parser->map.height++;
}

void	parse_cub(t_parser *parser, char *cub)
{
	parser_init(parser);
	parser->fd = open(cub, O_RDONLY);
	if (parser->fd < 0)
		error_exit("cub file not found");
	while (parser->line && parser->sect != PS_DONE)
	{
		parser->line = get_next_line(parser->fd);
		check_section(parser);
		if (parser->sect == PS_NOTMAP)
			if (get_elem(parser, parser->line))
				parse_error_exit(parser, "illegal element");
		if (parser->sect == PS_MAP)
			get_map_data(parser, parser->line);
		free(parser->line);
	}
}
