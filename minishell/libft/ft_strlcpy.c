/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:54:52 by hyno              #+#    #+#             */
/*   Updated: 2021/07/09 15:40:48 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (src == 0)
		return (0);
	if (size == 0)
	{
		src_len = 0;
		while (src[src_len])
			src_len++;
		return (src_len);
	}
	i = 0;
	while (i + 1 < size)
	{
		dst[i] = src[i];
		if (src[i] == 0)
			return (i);
		i++;
	}
	dst[i] = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
