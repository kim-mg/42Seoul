/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:02:00 by myunkim           #+#    #+#             */
/*   Updated: 2022/03/29 18:38:45 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
