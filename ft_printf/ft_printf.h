/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:39:40 by myunkim           #+#    #+#             */
/*   Updated: 2021/07/01 01:25:39 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_form
{
	int		sign;
	int		minus;
	int		zero;
	int		width;
	int 	precision;
	char	type;
}				t_form;

// ft_printf.c
int				ft_type_check(char c, t_form *form);
void			ft_flags_check(char c, t_form *form, va_list ap);
void			ft_width_prec_check(char c, t_form *form, va_list ap);
int				ft_form_print(va_list ap, t_form *form);
int				ft_printf(const char *format, ...);

// ft_print_char.c
int				ft_print_str(char *s, t_form *form);
int				ft_print_char(char c, t_form *form);
#endif
