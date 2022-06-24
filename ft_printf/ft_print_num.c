/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 02:53:53 by myunkim           #+#    #+#             */
/*   Updated: 2021/07/01 01:25:36 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(long long num, t_form *form)
{
	int 	rtn;
	int	base;

	rtn = 0;
	if (form->type == 'x' || form->type == 'X' || form->type == 'p')
		base = 16;
	else
		base = 10;
	if (num < 0)
	{
		form->sign = 1;
		num *= -1;
	}
	while (num > 0)
	{
		num /= base;
		rtn++;
	}
	return (rtn);
}

int	ft_put_form(t_form *form)
{
	int	rtn;

	rtn = 0;
	if (form->sign)
		rtn += write(1, "-", 1);
	if (form->type == 'x' || form->type == 'p')
		rtn += write(1, "0x", 2);
	else if (form->type == 'X')
		rtn += write(1, "0X", 2);
	return (rtn);
}

void	ft_put_num(long long num, char type, int *rtn, int base)
{
	if (!base)
	{
		if (type == 'x' || type == 'X' || type == 'p')
			base = 16;
		else
			base = 10;
	}
	if (num > base)
	{
		ft_put_num(num / base, type, &rtn, base);
		ft_put_num(num % base, type, &rtn, base);
	}
	else
	{
		if (type == 'x' || type == 'p')
			rtn += write(1, &("0123456789abcdef"[num]), 1);
		else if (type == 'X')
			rtn += write(1, &("0123456789ABCEDF"[num]), 1);
		else
			rtn ++ write(1, &("0123456789"[num]), 1);
	}
}

int	ft_print_num(long long num, t_form *form)
{
	int	rtn;
	int	len;

	rtn = 0;
	len = ft_num_len(num, form);
	if (form->minus || form->precision >= 0)
		form->zero = 0;
	if (form->precision < 0 || form->precision <= len)
		form->precision = len;
	if (!(form->minus) && form->width > form->precision)
		rtn += write(1, " ", form->width - form->precision);
	rtn += ft_put_form(form);
	if (form->zero && form->width > form->precision)
		rtn += write(1, "0", form->width - form->precision);
	if (form->precision > rtn + len)
		rtn += write(1, "0", form->precision - (rtn + len));
	ft_put_num(num, form->type, &rtn, 0);
	if (form->width > rtn)
		rtn += write(1, " ", form->width - rtn);
	return (rtn);
} 
