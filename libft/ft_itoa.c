/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:52:48 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/24 17:01:20 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_numsize(long long n)
{
	size_t	cnt;

	cnt = 1;
	if (n < 0)
	{
		n = -n;
		cnt++;
	}
	while (n > 9)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char			*ft_itoa(int n)
{
	char		*rtn;
	long long	num;
	size_t		numsize;

	num = (long long)n;
	numsize = ft_numsize(num);
	rtn = (char *)malloc(sizeof(char) * (numsize + 1));
	if (!rtn)
		return (NULL);
	if (num < 0)
	{
		*rtn = '-';
		num = -num;
	}
	if (num == 0)
		*rtn = '0';
	*(rtn + numsize) = '\0';
	while (num > 0)
	{
		*(rtn + numsize - 1) = (num % 10) + '0';
		num /= 10;
		numsize--;
	}
	return (rtn);
}
