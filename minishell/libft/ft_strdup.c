/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:13:51 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:13:52 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*rtn;

	len = 0;
	while (s[len])
		len++;
	rtn = malloc(len + 1);
	if (rtn == 0)
		return (0);
	len = 0;
	while (s[len])
	{
		rtn[len] = s[len];
		len++;
	}
	rtn[len] = 0;
	return (rtn);
}
