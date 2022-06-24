/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:45:30 by hyno              #+#    #+#             */
/*   Updated: 2021/07/08 12:10:05 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*mydest;
	unsigned char	*mysrc;

	if (n == 0)
		return (dest);
	mydest = (unsigned char *)dest;
	mysrc = (unsigned char *)src;
	if (mydest < mysrc)
	{
		i = -1;
		while (++i < (int)n)
			mydest[i] = mysrc[i];
	}
	else if (mydest > mysrc)
	{
		i = (int)n;
		while (--i >= 0)
			mydest[i] = mysrc[i];
	}
	return (mydest);
}
