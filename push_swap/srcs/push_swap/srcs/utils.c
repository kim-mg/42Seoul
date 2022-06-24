/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:03:52 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:43:09 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

char	*ft_strdup(const char *s)
{
	char	*rtn;
	size_t	s_size;
	size_t	cp_len;

	s_size = 0;
	while (*(s + s_size) != '\0')
		s_size++;
	rtn = (char *)malloc(sizeof(char) * ++s_size);
	if (!rtn)
		return (NULL);
	cp_len = 0;
	while (s_size > 0)
	{
		*(rtn + cp_len) = *(s + cp_len);
		cp_len++;
		s_size--;
	}
	return (rtn);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi_ptr(const char *nptr, int *num)
{
	long long	rst;
	long long	sign;
	long long	i;

	rst = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (nptr[i] == '\0')
		return (1);
	while (nptr[i] != '\0' && '0' <= nptr[i] && nptr[i] <= '9')
		rst = (rst * 10) + (nptr[i++] - '0');
	if (nptr[i] != '\0' || rst * sign > 2147483647 || rst * sign < -2147483648)
		return (1);
	*num = rst * sign;
	return (0);
}
