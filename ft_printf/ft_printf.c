/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:07:50 by myunkim           #+#    #+#             */
/*   Updated: 2021/07/01 01:25:38 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int		ft_type_check(char c, t_form *form)
{
	if (c == 'c')
		form->type = 'c';
	else if (c == 's')
		form->type = 's';
	else if (c == 'p')
		form->type = 'p';
	else if (c == 'd')
		form->type = 'd';
	else if (c == 'i')
		form->type = 'i';
	else if (c == 'u')
		form->type = 'u';
	else if (c == 'x')
		form->type = 'x';
	else if (c == 'X')
		form->type = 'X';
	else if (c == '%')
		form->type = '%';
	return (form->type);
}

void	ft_flags_check(char c, t_form *form, va_list ap)
{
	if (c == '-')
		form->minus = 1;
	else if (!(form->width) && !(form->precision) && c == '0')
		form->zero = 1;
	else if (c == '.')
		form->prec = 0;
	else if (c == '*' || ft_isdigit(c))
		ft_width_prec_check(c, form, ap);
}

void	ft_width_prec_check(char c, t_form *form, va_list ap)
{
	if (c == '*')
	{
		if (!(form->prec_check))
		{
			if ((form->width = va_arg(ap, int)) < 0)
			{
				form->minus = 1;
				form->width *= -1;
			}
		}
		else
			form->precision = va_arg(ap, int);
	}
	else if (ft_isdigit(c))
	{
		if (form->prec_check)
			form->precision = form->precision * 10 + (c - '0');
		else
			form->width = form->width * 10 + (c - '0');
	}
}

int		ft_form_print(va_list ap, t_form *form)
{
	int		rtn;

	rtn = 0;
	if (form->type == 'c' || form->type == '%')
		rtn = ft_print_char((char)va_arg(ap, long long), form);
	else if (form->type == 's')
		rtn = ft_print_str((char *)va_arg(ap, long long), form);
	else if (form->type == 'p')
		rtn = ft_print_ptr(va_arg(ap, long long), form);
	else if (form->type == 'd' || form->type == 'i' || form->type == 'u' ||
			form->type == 'x' || form->type == 'X')
		rtn = ft_print_num(va_arg(ap, long long), form);
	else if (form->type == 'u' || form->type == 'x' || form->type == 'X')

	return (rtn);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_form	form;
	int		rtn;

	rtn = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_memset(&form, 0, sizeof(t_form));
			form.precision = -1;
			while (*(++format) && !(ft_type_check(*format, &form)))
				ft_flags_check(*format, &form, ap);
			rtn += ft_form_print (ap, &form);
		}
		else
			rtn += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (rtn);
}
