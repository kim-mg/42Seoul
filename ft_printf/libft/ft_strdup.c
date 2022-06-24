/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:13:56 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 19:00:56 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*rtn;
	size_t	s_size;
	size_t	cp_len;

	s_size = 0;
	while (*(s + s_size) != '\0')
		s_size++;
	rtn = (char *)malloc(sizeof(char) * ++s_size);
	if (!rtn)
		return (NULL);
	cp_len = 0;
	while (s_size > 0)
	{
		*(rtn + cp_len) = *(s + cp_len);
		cp_len++;
		s_size--;
	}
	return (rtn);
}
