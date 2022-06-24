/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:16:42 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/11 04:16:45 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_alignment_check(int *arr, size_t size)
{
	size_t	i;
	int		rtn;

	rtn = 0;
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			rtn = 1;
		i++;
	}
	return (rtn);
}

void	swap_each(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_pivot(int *arr, size_t size, size_t high, int piv)
{
	size_t	low;

	if (!pivot_alignment_check(arr, size)
		|| size == 1 || (size == 2 && arr[0] > arr[1]))
		return ;
	low = 1;
	while (low < size - 1 && high > 1 && low <= high)
	{
		if (arr[low] < piv && arr[high] > piv)
			swap_each(&arr[low], &arr[high]);
		if (arr[low] > piv)
			low++;
		if (arr[high] < piv)
			high--;
	}
	if (arr[high] > piv)
		swap_each(&arr[0], &arr[high]);
	sort_pivot(arr, high, high - 1, arr[0]);
	sort_pivot(&arr[low], size - low, size - low - 1, arr[low]);
}

int	init_pivot(t_stack *s, t_pivot *p)
{
	size_t	size;
	size_t	i;

	size = s->max_size;
	p->stack_p.array = malloc(sizeof(int) * size);
	if (!p->stack_p.array)
		return (1);
	i = 0;
	while (i < size)
	{
		p->stack_p.array[i] = s->array[i];
		i++;
	}
	p->stack_p.size = s->size;
	p->stack_p.max_size = s->max_size;
	sort_pivot(p->stack_p.array, size, size - 1, p->stack_p.array[0]);
	p->pvt[0] = 0;
	p->pvt[1] = 0;
	return (0);
}
