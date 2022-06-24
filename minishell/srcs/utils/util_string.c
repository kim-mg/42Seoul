/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:46 by hyno              #+#    #+#             */
/*   Updated: 2022/06/20 20:21:44 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

char	*addstr(char *str1, char *str2)
{
	char	*rtn;

	if (str1 == 0 && str2 == 0)
		return (0);
	if (str1 == 0)
	{
		rtn = ft_malloc_guard(ft_strdup(str2));
		return (rtn);
	}
	if (str2 == 0)
		return (str1);
	rtn = ft_malloc_guard(ft_strjoin(str1, str2));
	if (str1)
		free(str1);
	return (rtn);
}

char	*addchar(char *str, char word)
{
	char	*rtn;
	char	str2[2];

	rtn = 0;
	str2[0] = word;
	str2[1] = 0;
	if (str == 0)
	{
		rtn = ft_malloc_guard(ft_strdup(str2));
		return (rtn);
	}
	rtn = ft_malloc_guard(ft_strjoin(str, str2));
	free(str);
	return (rtn);
}
