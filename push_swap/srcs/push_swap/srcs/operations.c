/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:55:40 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/11 04:55:56 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *s)
{
	size_t	top;
	int		temp;

	if (s->size > 1)
	{
		top = s->size - 1;
		temp = s->array[top];
		s->array[top] = s->array[top - 1];
		s->array[top - 1] = temp;
	}
}

void	push_to_stack(t_stack *a, t_stack *b)
{
	size_t	a_top;
	size_t	b_top;

	if (a->size > 0)
	{
		a_top = a->size - 1;
		b_top = b->size;
		b->array[b_top] = a->array[a_top];
		a->size--;
		b->size++;
	}
}

void	rotate_stack(t_stack *s)
{
	size_t	top;
	int		temp;

	if (s->size > 1)
	{
		top = s->size - 1;
		temp = s->array[top];
		while (top > 0)
		{
			s->array[top] = s->array[top - 1];
			top--;
		}
		s->array[top] = temp;
	}
}

void	reverse_rotate_stack(t_stack *s)
{
	size_t	bot;
	int		temp;

	if (s->size > 1)
	{
		bot = 0;
		temp = s->array[bot];
		while (bot < s->size - 1)
		{
			s->array[bot] = s->array[bot + 1];
			bot++;
		}
		s->array[bot] = temp;
	}
}
