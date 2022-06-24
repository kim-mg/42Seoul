/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:13:34 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:13:14 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_counter
{
	size_t			i;
	size_t			ra;
	size_t			rb;
	size_t			pa;
	size_t			pb;
}			t_counter;

typedef struct s_stack
{
	int				*array;
	size_t			size;
	size_t			max_size;
}			t_stack;

// add stacks
typedef struct s_stacks
{
	t_stack			a;
	t_stack			b;
}			t_stacks;

typedef struct s_pivot
{
	t_stack			stack_p;
	int				pvt[2];
}			t_pivot;

typedef struct s_instruction
{
	char			*line;
	void			*next;
	void			*prev;
}			t_instruction;

typedef struct s_process
{
	t_stacks		stack;
	t_pivot			pivot;
	t_instruction	*instr;
}			t_process;

// ===============================================================
// clean.c

void				free_instructions(t_instruction *instr);
void				free_proc(t_process *proc);

int					overlap_check(t_stack *stack, int num);
int					put_args_stack(char *args, t_stack *stack);
int					fill_stack(int argc, char *argv[], t_stack *stack);
size_t				count_stack_size(int argc, char *argv[]);
int					init_stack(int argc, char *argv[],
						t_stack *stack_a, t_stack *stack_b);

t_instruction		*add_instr(t_instruction **instr, char *line);
void				execute_instr(char *line, t_stack *a, t_stack *b);
void				link_execute_instr(t_instruction **instr, char *line,
						t_stacks *s, t_counter *cnt);

void				swap_stack(t_stack *s);
void				push_to_stack(t_stack *a, t_stack *b);
void				rotate_stack(t_stack *s);
void				reverse_rotate_stack(t_stack *s);

int					pivot_alignment_check(int *arr, size_t size);
void				swap_each(int *a, int *b);
void				sort_pivot(int *arr, size_t size, size_t high, int piv);
int					init_pivot(t_stack *s, t_pivot *p);

void				get_pivot(t_stack *s, t_pivot *p, size_t n);
size_t				get_start_i(t_stack *s, int pivot, size_t n, size_t is_a);
t_counter			init_cnt(t_stack *s, t_pivot *p, size_t n, size_t is_a);
int					alignment_check(t_stack *s, size_t n, size_t asc);

void				proc_rrr_stack(t_stacks *s,
						t_instruction **instr, t_counter *cnt);
void				proc_small_a(t_stacks *s, t_pivot *pivot,
						t_instruction **instr, size_t n);
void				proc_small_b(t_stacks *s, t_pivot *pivot,
						t_instruction **instr, size_t n);
void				a_to_b(t_stacks *s, t_pivot *pivot,
						t_instruction **instr, size_t n);
void				b_to_a(t_stacks *s, t_pivot *pivot,
						t_instruction **instr, size_t n);

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
int					ft_isspace(char c);
int					ft_atoi_ptr(const char *nptr, int *num);

#endif
