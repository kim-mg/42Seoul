/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 02:53:53 by myunkim           #+#    #+#             */
/*   Updated: 2021/07/06 14:07:13 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned long long *num, t_form *form)
{
	int					rtn;
	unsigned int		base;
	unsigned long long	temp;

	rtn = 1;
	temp = *num;
	if ((form->type == 'd' || form->type == 'i') && (long long)temp < 0)
	{
		form->sign = 1;
		temp = -temp;
		*num = temp;
	}
	if (form->type == 'x' || form->type == 'X' || form->type == 'p')
		base = 16;
	else
		base = 10;
	while (temp >= base)
	{
		temp /= base;
		rtn++;
	}
	return (rtn);
}

int	ft_set_num(unsigned long long *num, t_form *form)
{
	int	len;

	len = ft_num_len(num, form);
	if (form->minus || form->precision > -1)
		form->zero = 0;
	if (form->sign || form->plus)
		form->space = 0;
	if (form->sign)
		form->plus = 0;
	if ((form->sharp || form->type == 'p') && (form->type == 'p'
			|| ((form->type == 'x' || form->type == 'X') && *num != 0)))
		form->formlen = 2;
	form->formlen += form->sign + form->space + form->plus;
	if ((form->precision == -1 || form->precision <= len)
		&& (form->precision != 0 || *num != 0))
		form->precision = len;
	return (len);
}

int	ft_put_form(unsigned long long num, t_form *form)
{
	int	rtn;

	rtn = 0;
	if (form->plus)
		form->space = 0;
	if (form->space || form->plus || form->sign)
	{
		if (form->sign)
			rtn += write(1, "-", 1);
		else if (form->plus)
			rtn += write(1, "+", 1);
		else if (form->space)
			rtn += write(1, " ", 1);
	}
	if ((form->sharp || form->type == 'p'))
	{
		if (form->type == 'p' || (form->type == 'x' && num != 0))
			rtn += write(1, "0x", 2);
		else if (form->type == 'X' && num != 0)
			rtn += write(1, "0X", 2);
	}
	return (rtn);
}

void	ft_put_num(unsigned long long num, char type,
		int *rtn, unsigned int base)
{
	if (!base)
	{
		if (type == 'x' || type == 'X' || type == 'p')
			base = 16;
		else
			base = 10;
	}
	if (num >= base)
	{
		ft_put_num(num / base, type, rtn, base);
		ft_put_num(num % base, type, rtn, base);
	}
	else
	{
		if (type == 'X')
			*rtn += write(1, &("0123456789ABCDEF"[num]), 1);
		else
			*rtn += write(1, &("0123456789abcdef"[num]), 1);
	}
}

int	ft_print_num(unsigned long long num, t_form *form)
{
	int	rtn;
	int	len;

	rtn = 0;
	len = ft_set_num(&num, form);
	if (form->minus == 0 && form->zero == 0)
		while (rtn < (form->width - form->precision - form->formlen))
			rtn += write(1, " ", 1);
	rtn += ft_put_form(num, form);
	if (form->zero)
		while (rtn < (form->width - form->precision))
			rtn += write(1, "0", 1);
	while (len++ < form->precision)
		rtn += write(1, "0", 1);
	if (form->precision != 0)
		ft_put_num(num, form->type, &rtn, 0);
	while (rtn < form->width)
		rtn += write(1, " ", 1);
	return (rtn);
}
