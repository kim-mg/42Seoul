/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:06:42 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/21 17:12:54 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	cpy_dstsize;

	dst_length = ft_strlen((const char *)dst);
	src_length = ft_strlen(src);
	cpy_dstsize = dstsize;
	while (*dst != '\0' && cpy_dstsize > 0)
	{
		dst++;
		cpy_dstsize--;
	}
	if (dstsize == 0)
		return (src_length);
	else if (dst_length >= dstsize)
		return (dstsize + src_length);
	while (*src != '\0' && cpy_dstsize > 1)
	{
		*dst++ = *src++;
		cpy_dstsize--;
	}
	*dst = '\0';
	return (dst_length + src_length);
}
