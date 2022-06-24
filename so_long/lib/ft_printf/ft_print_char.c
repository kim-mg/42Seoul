/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 22:53:59 by myunkim           #+#    #+#             */
/*   Updated: 2021/07/03 01:42:35 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_width(t_form *form)
{
	int	rtn;

	rtn = 0;
	while (rtn + 1 < form->width)
	{
		if (form->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		rtn++;
	}
	return (rtn);
}

int	ft_print_char(char c, t_form *form)
{
	int	rtn;

	rtn = 0;
	if (form->type == '%')
		c = '%';
	if (form->minus && form->zero)
		form->zero = 0;
	if (form->minus)
	{
		rtn += write(1, &c, 1);
		rtn += ft_put_width(form);
	}
	else
	{
		rtn += ft_put_width(form);
		rtn += write(1, &c, 1);
	}
	return (rtn);
}

int	ft_print_str(char *s, t_form *form)
{
	int	rtn;

	rtn = 0;
	if (s == 0)
		s = "(null)";
	if (form->minus)
		form->zero = 0;
	if (form->precision < 0 || form->precision >= (int)ft_strlen(s))
		form->precision = (int)ft_strlen(s);
	if (form->minus == 0 && form->zero == 0)
		while (rtn < form->width - form->precision)
			rtn += write(1, " ", 1);
	if (form->zero)
		while (rtn < form->width - form->precision)
			rtn += write(1, "0", 1);
	rtn += write(1, s, form->precision);
	if (form->minus && form->width > form->precision)
		while (rtn < form->width)
			rtn += write(1, " ", 1);
	return (rtn);
}
