/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:47:39 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/19 21:46:14 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	rst;
	size_t	i;

	rst = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	while (*(src + rst) != '\0')
		rst++;
	if (dstsize > 0)
	{
		while (*(src + i) != '\0' && i < dstsize)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		if (dstsize <= rst)
			*(dst + i - 1) = '\0';
		else
			*(dst + i) = '\0';
	}
	return (rst);
}
