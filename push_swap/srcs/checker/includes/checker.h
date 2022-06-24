/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:25:12 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:04:47 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>

typedef struct s_stack
{
	int			*array;
	size_t		size;
	size_t		max_size;
}			t_stack;

int			overlap_check(t_stack *stack, int num);
int			put_args_stack(char *args, t_stack *stack);
int			fill_stack(int argc, char *argv[], t_stack *stack);
size_t		count_stack_size(int argc, char *argv[]);
int			init_stack(int argc, char *argv[],
				t_stack *stack_a, t_stack *stack_b);

ssize_t		ft_findnl(char *s);
char		*ft_stradd(char *s1, char *s2);
void		ft_putgnl(char **dst, char **src, ssize_t nl_idx);
int			ft_checkeof(char **dst, char **src, ssize_t r_size);
int			get_next_line(int fd, char **line);

char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memmove(void *dst, const void *src, size_t len);

void		swap_stack(t_stack *s);
void		push_to_stack(t_stack *a, t_stack *b);
void		rotate_stack(t_stack *s);
void		reverse_rotate_stack(t_stack *s);

size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
int			ft_isspace(char c);
int			ft_atoi_ptr(const char *nptr, int *num);

#endif
