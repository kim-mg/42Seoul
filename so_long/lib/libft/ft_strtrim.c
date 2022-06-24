/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:18:17 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/24 17:01:34 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i) != '\0')
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = 0;
	while (ft_checkset(*(s1 + i), set) && *(s1 + i) != '\0')
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_checkset(*(s1 + j), set) && j > 0)
		j--;
	if (i >= j)
		return (ft_strdup(""));
	rtn = (char *)malloc(sizeof(char) * (j - i + 1 + 1));
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, (s1 + i), (j - i + 1 + 1));
	return (rtn);
}
