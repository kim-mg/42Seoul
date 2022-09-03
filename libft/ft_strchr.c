/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 02:16:14 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 19:00:47 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;
	char	cast_c;

	cast_c = (char)c;
	s_ptr = (char *)s;
	while (*s_ptr != '\0')
	{
		if (*s_ptr == cast_c)
			return (s_ptr);
		s_ptr++;
	}
	if (cast_c && *s_ptr == cast_c)
		return (s_ptr);
	return (NULL);
}
