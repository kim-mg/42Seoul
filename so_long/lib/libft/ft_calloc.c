/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:43:57 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/23 18:56:11 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtn;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(sizeof(char) * 1));
	if (nmemb * size > 2147483647)
		return (NULL);
	rtn = malloc(nmemb * size);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*((unsigned char *)rtn + i) = 0;
		i++;
	}
	return (rtn);
}
