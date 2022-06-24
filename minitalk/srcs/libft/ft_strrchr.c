/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:53:02 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 19:07:47 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_ptr;
	char	*rtn_ptr;
	char	cast_c;

	s_ptr = (char *)s;
	rtn_ptr = NULL;
	cast_c = (char)c;
	while (*s_ptr != '\0')
	{
		if (*s_ptr == cast_c)
			rtn_ptr = s_ptr;
		s_ptr++;
	}
	if (*s_ptr == cast_c)
		rtn_ptr = s_ptr;
	return (rtn_ptr);
}
