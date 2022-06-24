/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:23:29 by hyno              #+#    #+#             */
/*   Updated: 2021/07/08 09:53:53 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < len && big[i] != 0)
	{
		j = 0;
		while (i + j < len && little[j] == big[i + j])
		{
			if (little[j + 1] == 0)
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (0);
}
