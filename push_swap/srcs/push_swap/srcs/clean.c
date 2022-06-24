/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:21:56 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/11 04:21:57 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_instructions(t_instruction *instr)
{
	t_instruction	*temp;

	while (instr)
	{
		temp = instr->next;
		free(instr->line);
		free(instr);
		instr = temp;
	}
}

void	free_proc(t_process *proc)
{
	free_instructions(proc->instr);
	free(proc->stack.a.array);
	free(proc->stack.b.array);
	free(proc->pivot.stack_p.array);
}
