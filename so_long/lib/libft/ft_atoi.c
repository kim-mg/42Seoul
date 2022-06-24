/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:51:39 by myunkim           #+#    #+#             */
/*   Updated: 2022/03/29 18:55:38 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_flowcheck(long long num)
{
	if (num > 2147483647)
		return (-1);
	if (num < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long	rst;
	long long	sign;
	long long	i;

	rst = 0;
	sign = 1;
	i = 0;
	while (*(nptr + i) != '\0' && ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while (*(nptr + i) != '\0' && '0' <= *(nptr + i) && *(nptr + i) <= '9')
		rst = (rst * 10) + (*(nptr + i++) - '0');
	if (ft_flowcheck(rst * sign) != 1)
		return (ft_flowcheck(rst * sign));
	return ((int)(rst * sign));
}
