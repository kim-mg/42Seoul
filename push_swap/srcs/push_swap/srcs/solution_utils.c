/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:44:29 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/11 04:44:30 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivot(t_stack *s, t_pivot *p, size_t n)
{
	int		max;
	size_t	i;

	max = s->array[s->size - 1];
	i = s->size - n;
	while (i < s->size)
	{
		if (s->array[i] > max)
			max = s->array[i];
		i++;
	}
	i = 0;
	while (i < p->stack_p.max_size && p->stack_p.array[i] != max)
		i++;
	if (n == 2)
	{
		p->pvt[0] = p->stack_p.array[i];
		p->pvt[1] = p->stack_p.array[i + 1];
	}
	else
	{
		p->pvt[0] = p->stack_p.array[i + (n / 3)];
		p->pvt[1] = p->stack_p.array[i + (2 * (n / 3))];
	}
}

size_t	get_start_i(t_stack *s, int pivot, size_t n, size_t is_a)
{
	size_t	i;
	size_t	rtn;

	i = s->size - n;
	rtn = 0;
	while (i < s->size)
	{
		if ((is_a && s->array[i] < pivot) || (!is_a && s->array[i] > pivot))
			break ;
		i++;
		rtn++;
	}
	return (rtn);
}

t_counter	init_cnt(t_stack *s, t_pivot *p, size_t n, size_t is_a)
{
	t_counter	cnt;

	if (is_a)
		cnt.i = get_start_i(s, p->pvt[0], n, is_a);
	else
		cnt.i = get_start_i(s, p->pvt[1], n, is_a);
	cnt.ra = 0;
	cnt.rb = 0;
	cnt.pa = 0;
	cnt.pb = 0;
	return (cnt);
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
