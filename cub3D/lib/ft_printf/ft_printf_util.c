/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 07:47:22 by myunkim           #+#    #+#             */
/*   Updated: 2021/07/06 14:12:31 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_proc_dip(va_list ap, t_form *form)
{
	if (form->type == 'p')
		return (ft_print_num((unsigned long long)va_arg(ap, void *), form));
	if (form->length == 1)
		return (ft_print_num((short int)va_arg(ap, long long), form));
	else if (form->length == 2)
		return (ft_print_num((signed char)va_arg(ap, long long), form));
	else if (form->length == 4)
		return (ft_print_num((long)va_arg(ap, long long), form));
	else if (form->length == 8)
		return (ft_print_num((long long)va_arg(ap, long long), form));
	else
		return (ft_print_num((unsigned long long)va_arg(ap, int), form));
}

int	ft_print_proc_ux(va_list ap, t_form *form)
{
	if (form->length == 1)
		return (ft_print_num(
				(unsigned short int)va_arg(ap, unsigned int), form));
	else if (form->length == 2)
		return (ft_print_num(
				(unsigned char)va_arg(ap, unsigned int), form));
	else if (form->length == 4)
		return (ft_print_num(va_arg(ap, unsigned long), form));
	else if (form->length == 8)
		return (ft_print_num(va_arg(ap, unsigned long long), form));
	else
		return (ft_print_num(va_arg(ap, unsigned int), form));
}

int	ft_print_proc_char(va_list ap, t_form *form)
{
	if (form->type == 'c')
	{
		if (form->length == 4)
			return (ft_print_char((wint_t)va_arg(ap, int), form));
		else
			return (ft_print_char((char)va_arg(ap, int), form));
	}
	else if (form->type == 's')
	{
		if (form->length == 4)
			return (ft_print_str((char *)va_arg(ap, wchar_t *), form));
		else
			return (ft_print_str((char *)va_arg(ap, char *), form));
	}
	else
		return (ft_print_char(0, form));
}

void	ft_print_proc_n(va_list ap, t_form *form, int n)
{
	if (form->length == 1)
		*((short int *)va_arg(ap, int *)) = n;
	else if (form->length == 2)
		*((signed char *)va_arg(ap, int *)) = n;
	else if (form->length == 4)
		*((long int *)va_arg(ap, int *)) = n;
	else if (form->length == 8)
		*((long long int *)va_arg(ap, int *)) = n;
	else
		*(va_arg(ap, int *)) = n;
}
