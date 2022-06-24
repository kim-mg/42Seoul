/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:15:39 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 18:58:42 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (n > 0)
	{
		if (*src_ptr == (unsigned char)c)
		{
			*dst_ptr = *src_ptr;
			return (dst_ptr + 1);
		}
		*dst_ptr++ = *src_ptr++;
		n--;
	}
	return (NULL);
}
