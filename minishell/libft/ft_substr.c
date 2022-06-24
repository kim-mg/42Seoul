/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:22 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:14:23 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		rtn = malloc(1);
		if (rtn == 0)
			return (0);
		rtn[0] = 0;
		return (rtn);
	}
	i = start;
	while (s[i] && i < start + len)
		i++;
	rtn = malloc(i - start + 1);
	if (rtn == 0)
		return (0);
	i = 0;
	while (s[i + start] && (i + start) < start + len)
	{
		rtn[i] = s[i + start];
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
