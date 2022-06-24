/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:56:30 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:20:22 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	init_proc(int argc, char *argv[], t_process *proc)
{
	proc->instr = NULL;
	if (init_stack(argc, argv, &proc->stack.a, &proc->stack.b))
		return (1);
	if (init_pivot(&proc->stack.a, &proc->pivot))
	{
		free(proc->stack.a.array);
		free(proc->stack.b.array);
		return (1);
	}
	return (0);
}

void	print_instructions(t_instruction **instr)
{
	t_instruction	*temp;

	if (!instr)
		return ;
	temp = *instr;
	while (temp)
	{
		write(STDOUT_FILENO, temp->line, ft_strlen(temp->line));
		write(STDOUT_FILENO, "\n", 1);
		temp = temp->next;
	}
}

int	solution(t_process *proc)
{
	a_to_b(&proc->stack, &proc->pivot, &proc->instr, proc->stack.a.max_size);
	if (alignment_check(&proc->stack.a, proc->stack.a.max_size, 1)
		|| proc->stack.b.size != 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_process	proc;

	if (--argc < 1)
		return (0);
	if (init_proc(argc, &argv[1], &proc))
		return (0);
	if (solution(&proc))
	{
		free_proc(&proc);
		write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	print_instructions(&proc.instr);
	free_proc(&proc);
	return (0);
}
