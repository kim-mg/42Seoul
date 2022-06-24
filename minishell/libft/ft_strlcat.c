/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:10:24 by hyno              #+#    #+#             */
/*   Updated: 2021/07/09 15:50:05 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	j;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	dst += dst_len;
	j = 0;
	while (dst_len + j + 1 < size && src[j])
	{
		*dst = src[j];
		dst++;
		j++;
	}
	*dst = 0;
	if (size < dst_len)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
