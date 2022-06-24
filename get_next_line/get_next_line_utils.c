/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:15:41 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/01 22:13:59 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s, int size)
{
	char	*rtn;
	int		cp_len;

	rtn = (char *)malloc(sizeof(char) * (size + 1));
	if (!rtn)
		return (NULL);
	cp_len = 0;
	while (*(s + cp_len))
	{
		*(rtn + cp_len) = *(s + cp_len);
		cp_len++;
	}
	*(rtn + cp_len) = '\0';
	return (rtn);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, t_info *info)
{
	char	*rtn;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (BUFFER_SIZE < 100)
		rtn = (char *)malloc((info->aloc_size + 100 + 1));
	else
		rtn = (char *)malloc((info->aloc_size + BUFFER_SIZE + 1));
	if (!rtn)
		return (NULL);
	i = -1;
	while (*(s1 + ++i))
		*(rtn + i) = *(s1 + i);
	j = -1;
	while (*(s2 + ++j))
		*(rtn + i++) = *(s2 + j);
	*(rtn + i) = '\0';
	return (rtn);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize, t_info *info)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	cpy_dstsize;

	dst_length = info->sto_size;
	src_length = info->r_size;
	cpy_dstsize = dstsize;
	dst += info->sto_size;
	dstsize += info->sto_size;
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
