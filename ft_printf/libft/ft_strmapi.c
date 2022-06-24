/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 02:30:31 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 19:06:02 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(rtn + i) = f((unsigned int)i, *(s + i));
		i++;
	}
	*(rtn + i) = '\0';
	return (rtn);
}
