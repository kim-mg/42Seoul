#include <fcntl.h>
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../includes/cub3d.h"

t_element	*new_elem(t_element *head, char *cont, t_parse_section sect, t_identity ident)
{
	t_element	*new;

	new = (t_element *)ft_calloc(sizeof(t_element), 1);
	if (!new)
		return (NULL);
	new->sect = sect;
	new->ident = ident;
	new->content = ft_strtrim(cont, "\n");
	if (head)
		new->head = head;
	else
		new->head = NULL;
	new->next = NULL;
	return (new);
}

void	add_elem(t_element **e_head, char *cont, t_parse_section sect, t_identity ident)
{
	t_element	*temp;

	if (!(*e_head))
	{
		*e_head = new_elem(NULL, cont, sect, ident);
		(*e_head)->head = *e_head;
		return ;
	}
	temp = *e_head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem(*e_head, cont, sect, ident);
}

char	**pre_proc_elem(char *line)
{
	char	**rtn;
	char	*temp;
	int	i;

	rtn = ft_split(line, ' ');
	i = 0;
	while (*(rtn + i))
		i++;
	if (i < 2 || 5 < i)
	{
		free_strarr(rtn);
		return (NULL);
	}
	if (2 < i && i < 5)
	{
		i = 2;
		while (*(rtn + i))
		{
			temp = rtn[1];
			rtn[1] = ft_strjoin(temp, *(rtn + i++));
			free(temp);
		}
	}
	return (rtn);
}

int	get_elem(t_parser *parser, char *line)
{
	char	**split;

	split = pre_proc_elem(line);
	if (!split)
		return (1);
	if (!ft_strncmp(split[0], "NO", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_NORTH);
	else if (!ft_strncmp(split[0], "SO", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_SOUTH);
	else if (!ft_strncmp(split[0], "WE", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_WEST);
	else if (!ft_strncmp(split[0], "EA", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_TEXTURE, ID_EAST);
	else if (!ft_strncmp(split[0], "F", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_LAYER, ID_FLOOR);
	else if (!ft_strncmp(split[0], "C", ft_strlen(split[0]) + 1))
		add_elem(&parser->elem_head, split[1], PS_LAYER, ID_CEILING);
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
	if (parser->sect == PS_NOTMAP)
	{
		while (*parser->line == '\n')
		{
			free(parser->line);
			parser->line = get_next_line(parser->fd);
			if (*parser->line != '\n')
				parser->sect_cnt++;
		}
		if (parser->sect_cnt >= 2 && parser->elem_cnt >= 6)
			parser->sect = PS_MAP;
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
