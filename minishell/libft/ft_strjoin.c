/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:07 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:14:07 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;

	rtn = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (rtn == 0)
		return (0);
	ft_strlcpy(rtn, s1, ft_strlen(s1) + 1);
	ft_strlcat(rtn, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (rtn);
}
