/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:12:06 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:12:06 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elt_count, size_t elt_size)
{
	void	*rtn;
	size_t	i;

	rtn = malloc(elt_count * elt_size);
	if (rtn == 0)
		return (0);
	i = 0;
	while (i < elt_count * elt_size)
	{
		((unsigned char *)rtn)[i] = 0;
		i++;
	}
	return (rtn);
}
