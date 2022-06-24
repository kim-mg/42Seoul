/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:57:13 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 18:59:43 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	cpy_c;

	ptr = (unsigned char *)b;
	cpy_c = (unsigned char)c;
	while (len > 0)
	{
		*ptr++ = cpy_c;
		len--;
	}
	return (b);
}
