#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../includes/cub3d.h"

t_element	*new_elem(t_element *head, char *cont,
						t_parse_section sect, t_identity ident)
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

void	add_elem(t_element **e_head, char *cont,
					t_parse_section sect, t_identity ident)
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
	int		i;

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
