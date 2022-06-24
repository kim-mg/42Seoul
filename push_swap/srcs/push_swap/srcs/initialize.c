/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:14:04 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/11 04:14:05 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	overlap_check(t_stack *stack, int num)
{
	size_t	i;

	i = stack->max_size;
	while (i > stack->max_size - stack->size)
	{
		if (stack->array[i - 1] == num)
			return (1);
		i--;
	}
	return (0);
}

int	put_args_stack(char *args, t_stack *stack)
{
	char	*arg;
	char	*temp;
	int		num;

	while (*args)
	{
		while (*args && *args == ' ')
			args++;
		temp = args;
		while (*args && *args != ' ')
			args++;
		if (*args == ' ' && *args != '\0')
			*(args++) = '\0';
		arg = ft_strdup(temp);
		if (!arg)
			return (1);
		if (ft_atoi_ptr(arg, &num) || overlap_check(stack, num))
			return (1);
		stack->array[stack->max_size - 1 - stack->size] = num;
		stack->size++;
		free(arg);
	}
	return (0);
}

int	fill_stack(int argc, char *argv[], t_stack *stack)
{
	int		i;
	char	*args;

	i = 0;
	while (i < argc)
	{
		args = argv[i];
		if (put_args_stack(args, stack))
			return (1);
		i++;
	}
	return (0);
}

size_t	count_stack_size(int argc, char *argv[])
{
	int		i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!j || argv[i][j - 1] == ' ') && argv[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	init_stack(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;

	size = count_stack_size(argc, argv);
	if (!size)
		return (1);
	stack_a->array = malloc(sizeof(int) * size);
	if (!stack_a->array)
		return (write(STDERR_FILENO, "Error\n", 6));
	stack_b->array = malloc(sizeof(int) * size);
	if (!stack_b->array)
	{
		free(stack_a->array);
		return (write(STDERR_FILENO, "Error\n", 6));
	}
	stack_a->max_size = size;
	stack_b->max_size = size;
	stack_a->size = 0;
	stack_b->size = 0;
	if (fill_stack(argc, argv, stack_a))
	{
		free(stack_a->array);
		free(stack_b->array);
		return (write(STDERR_FILENO, "Error\n", 6));
	}
	return (0);
}
