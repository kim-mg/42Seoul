/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:26:26 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:05:20 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

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

int	alignment_check(t_stack *s, size_t n, size_t asc)
{
	size_t	i;

	i = s->size - n;
	while (i < s->size - 1)
	{
		if ((asc && s->array[i] < s->array[i + 1])
			|| (!asc && s->array[i] > s->array[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*cmd;

	if (--argc < 1)
		return (0);
	if (init_stack(argc, &argv[1], &stack_a, &stack_b))
		return (0);
	cmd = malloc(sizeof(char) * 5);
	if (!cmd)
		return (0);
	while (get_next_line(STDIN_FILENO, &cmd))
		execute_instr(cmd, &stack_a, &stack_b);
	if (alignment_check(&stack_a, stack_a.size, 1) || stack_b.size != 0)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	free(cmd);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}
