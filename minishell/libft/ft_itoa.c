/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:13:04 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:13:05 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_int_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (len == 0)
		len = 1;
	return (len);
}

int	subfunc0(int n, char *rtn)
{
	if (n < 0)
	{
		rtn[0] = '-';
		return (get_int_len(n) + 1);
	}
	else
	{
		rtn[0] = 48;
		return (get_int_len(n));
	}
}

char	*ft_itoa(int n)
{
	char	*rtn;
	int		i;

	if (n < 0)
		rtn = malloc(get_int_len(n) + 2);
	else
		rtn = malloc(get_int_len(n) + 1);
	if (rtn == 0)
		return (0);
	i = subfunc0(n, rtn);
	if (n > 0)
		n *= -1;
	rtn[i--] = 0;
	while (n != 0)
	{
		rtn[i--] = (-(n % 10) + 48);
		n /= 10;
	}
	return (rtn);
}
