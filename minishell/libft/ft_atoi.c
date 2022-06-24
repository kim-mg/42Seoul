/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:42:45 by hyno              #+#    #+#             */
/*   Updated: 2021/07/09 15:10:39 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	over_check(unsigned long res, long sign)
{
	unsigned long	big;

	big = 9223372036854775807;
	if (res >= big && sign == 1)
		return (-1);
	else if (res >= big + 1 && sign == -1)
		return (0);
	else
		return (1);
}

long	over_check_ten(unsigned long res, long sign)
{
	if (res >= 922337203685477581 && sign == 1)
		return (-1);
	else if (res >= 922337203685477581 && sign == -1)
		return (0);
	else
		return (1);
}

int	space_skip(const char *nptr)
{
	int	index;

	index = 0;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\n'
		|| nptr[index] == '\v' || nptr[index] == '\f' || nptr[index] == '\r')
		index++;
	return (index);
}

int	ft_atoi(const char *nptr)
{
	int				index;
	unsigned long	res;
	long			sign;

	index = space_skip(nptr);
	res = 0;
	sign = 1;
	if (nptr[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (nptr[index] == '+')
		index++;
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		if (over_check_ten(res, sign) != 1)
			return (over_check_ten(res, sign));
		res *= 10;
		res += nptr[index] - 48;
		index++;
		if (over_check(res, sign) != 1)
			return (over_check_ten(res, sign));
	}
	return ((long)res * sign);
}
