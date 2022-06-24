/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:21:43 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/17 18:03:37 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*rst_ptr;

	if (*((char *)little) == '\0')
		return ((char *)big);
	i = 0;
	while (*((char *)big + i) != '\0' && i < len)
	{
		rst_ptr = (char *)big + i;
		j = 0;
		while (*((char *)big + i + j) == *((char *)little + j) && i + j < len
			&& *((char *)little + j) != '\0')
			j++;
		if (*((char *)little + j) == '\0')
			return (rst_ptr);
		i++;
	}
	return (NULL);
}
