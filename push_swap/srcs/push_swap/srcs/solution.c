/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:19:21 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/11 04:19:22 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	proc_rrr_stack(t_stacks *s, t_instruction **instr, t_counter *cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt->ra && i < cnt->rb && s->a.size != cnt->ra)
	{
		link_execute_instr(instr, "rrr", s, cnt);
		i++;
	}
	while (i < cnt->ra && s->a.size != cnt->ra)
	{
		link_execute_instr(instr, "rra", s, cnt);
		i++;
	}
	while (i < cnt->rb)
	{
		link_execute_instr(instr, "rrb", s, cnt);
		i++;
	}
}

void	proc_small_a(t_stacks *s, t_pivot *pivot,
			t_instruction **instr, size_t n)
{
	t_counter	cnt;

	get_pivot(&s->a, pivot, n);
	cnt = init_cnt(&s->a, pivot, n, 1);
	while (alignment_check(&s->a, n, 1))
	{
		if (s->a.array[s->a.size - 1] > pivot->pvt[0])
			link_execute_instr(instr, "ra", s, &cnt);
		else if (s->a.array[s->a.size - 1] > s->a.array[s->a.size - 2])
			link_execute_instr(instr, "sa", s, &cnt);
		else
			link_execute_instr(instr, "rra", s, &cnt);
	}
}

void	proc_small_b(t_stacks *s, t_pivot *pivot,
			t_instruction **instr, size_t n)
{
	t_counter	cnt;

	if (n == 0)
		return ;
	get_pivot(&s->b, pivot, n);
	cnt = init_cnt(&s->b, pivot, n, 0);
	while (n > 0)
	{
		if (n == 2 && (s->b.array[s->b.size - 1] < s->b.array[s->b.size - 2]))
			link_execute_instr(instr, "sb", s, &cnt);
		link_execute_instr(instr, "pa", s, &cnt);
		n--;
	}
}

void	a_to_b(t_stacks *s, t_pivot *pivot, t_instruction **instr, size_t n)
{
	t_counter	cnt;

	if (n <= 1 || !(alignment_check(&s->a, n, 1)))
		return ;
	if (n == 2 || (n == 3 && s->a.size == 3))
		return (proc_small_a(s, pivot, instr, n));
	get_pivot(&s->a, pivot, n);
	cnt = init_cnt(&s->a, pivot, n, 1);
	while (cnt.i < n)
	{
		if (s->a.array[s->a.size - 1] >= pivot->pvt[0])
			link_execute_instr(instr, "ra", s, &cnt);
		else
		{
			link_execute_instr(instr, "pb", s, &cnt);
			if (s->b.array[s->b.size - 1] >= pivot->pvt[1])
				link_execute_instr(instr, "rb", s, &cnt);
		}
		cnt.i++;
	}
	proc_rrr_stack(s, instr, &cnt);
	a_to_b(s, pivot, instr, n - cnt.pb);
	b_to_a(s, pivot, instr, cnt.rb);
	b_to_a(s, pivot, instr, cnt.pb - cnt.rb);
}

void	b_to_a(t_stacks *s, t_pivot *pivot, t_instruction **instr, size_t n)
{
	t_counter	cnt;

	if (n <= 2)
		return (proc_small_b(s, pivot, instr, n));
	get_pivot(&s->b, pivot, n);
	cnt = init_cnt(&s->b, pivot, n, 0);
	while (cnt.i < n)
	{
		if (s->b.array[s->b.size - 1] <= pivot->pvt[1])
			link_execute_instr(instr, "rb", s, &cnt);
		else
		{
			link_execute_instr(instr, "pa", s, &cnt);
			if (s->a.array[s->a.size - 1] < pivot->pvt[0])
				link_execute_instr(instr, "ra", s, &cnt);
		}
		cnt.i++;
	}
	a_to_b(s, pivot, instr, cnt.pa - cnt.ra);
	proc_rrr_stack(s, instr, &cnt);
	a_to_b(s, pivot, instr, cnt.ra);
	b_to_a(s, pivot, instr, n - cnt.pa);
}
