/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:11:47 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:06:27 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(rtn + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(rtn + i) = *(s2 + j);
		i++;
		j++;
	}
	*(rtn + i) = '\0';
	return (rtn);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	if (dst <= src)
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			dst_ptr[len] = src_ptr[len];
		}
	}
	return (dst);
}
