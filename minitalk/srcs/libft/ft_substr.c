/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 06:42:41 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 19:08:18 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn_str;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		rtn_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		rtn_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn_str)
		return (NULL);
	i = 0;
	while (len > 0 && *((char *)s + start + i) != '\0')
	{
		*(rtn_str + i) = *((char *)s + start + i);
		i++;
		len--;
	}
	*(rtn_str + i) = '\0';
	return (rtn_str);
}
