/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:20 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:14:20 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_str(char c, char const *set)
{
	if (set == 0)
		return (0);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	int		i;
	char	*rtn;

	if (s1 == 0)
		return (0);
	front = 0;
	back = ft_strlen(s1) - 1;
	while (check_str(s1[front], set))
		front++;
	if (front == (int)ft_strlen(s1))
		return (ft_strdup(""));
	while (check_str(s1[back], set))
		back--;
	if (back - front < 0)
		return (ft_strdup(""));
	rtn = malloc(back - front + 2);
	if (rtn == 0)
		return (0);
	i = -1;
	while ((++i) + front <= back)
		rtn[i] = s1[front + i];
	rtn[i] = 0;
	return (rtn);
}
