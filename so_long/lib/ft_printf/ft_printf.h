/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:39:40 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/25 16:41:42 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct s_form
{
	int		sign;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		length;
	char	type;
	int		plus;
	int		space;
	int		sharp;
	int		formlen;
}				t_form;

int				ft_type_check(char c, t_form *form);
void			ft_flags_check(char c, t_form *form, va_list ap);
void			ft_width_prec_check(char c, t_form *form, va_list ap);
int				ft_form_print(va_list ap, t_form *form, int n);
int				ft_printf(const char *format, ...);

int				ft_put_width(t_form *form);
int				ft_print_str(char *s, t_form *form);
int				ft_print_char(char c, t_form *form);

int				ft_num_len(unsigned long long *num, t_form *form);
int				ft_set_num(unsigned long long *num, t_form *form);
int				ft_put_form(unsigned long long num, t_form *form);
void			ft_put_num(unsigned long long num, char type,
					int *rtn, unsigned int base);
int				ft_print_num(unsigned long long num, t_form *form);

int				ft_print_proc_dip(va_list ap, t_form *form);
int				ft_print_proc_ux(va_list ap, t_form *form);
int				ft_print_proc_char(va_list ap, t_form *form);
void			ft_print_proc_n(va_list ap, t_form *form, int n);
#endif
