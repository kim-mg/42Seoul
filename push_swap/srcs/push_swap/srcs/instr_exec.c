/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:56:59 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/11 04:57:00 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instruction	*add_instr(t_instruction **instr, char *line)
{
	t_instruction	*new;
	t_instruction	*temp;

	new = malloc(sizeof(t_instruction));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	if (!new->line)
	{
		free(new);
		return (NULL);
	}
	new->prev = NULL;
	new->next = NULL;
	temp = *instr;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
	{
		new->prev = temp;
		temp->next = new;
	}
	else
		*instr = new;
	return (new);
}

void	execute_instr(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss"))
		swap_stack(a);
	if (!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
		swap_stack(b);
	if (!ft_strcmp(line, "pb"))
		push_to_stack(a, b);
	if (!ft_strcmp(line, "pa"))
		push_to_stack(b, a);
	if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
		rotate_stack(a);
	if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
		rotate_stack(b);
	if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
		reverse_rotate_stack(a);
	if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		reverse_rotate_stack(b);
}

void	link_execute_instr(t_instruction **instr, char *line,
			t_stacks *s, t_counter *cnt)
{
	if (cnt)
	{
		if (!ft_strcmp(line, "pa"))
			cnt->pa++;
		if (!ft_strcmp(line, "pb"))
			cnt->pb++;
		if (!ft_strcmp(line, "ra"))
			cnt->ra++;
		if (!ft_strcmp(line, "rb"))
			cnt->rb++;
	}
	add_instr(instr, line);
	execute_instr(line, &s->a, &s->b);
}
