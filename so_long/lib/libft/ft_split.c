/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:32:37 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/24 17:02:05 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_cntsize(char const *s, char c)
{
	size_t	rtn;
	size_t	i;

	i = 0;
	rtn = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			i++;
		else
		{
			while (*(s + i) != '\0' && *(s + i) != c)
				i++;
			rtn++;
		}
	}
	return (rtn);
}

static char	**ft_rtnclear(char **lst, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*(lst + i) = NULL;
		free(*(lst + i));
		i++;
	}
	free(lst);
	return (NULL);
}

static char	**ft_dosplit(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	k;

	i = 0;
	k = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			i++;
		else
		{
			start = i;
			while (*(s + i) != '\0' && *(s + i) != c)
				i++;
			*(dst + k) = (char *)malloc(sizeof(char) * (i - start + 1));
			if (!(*(dst + k)))
				return (ft_rtnclear(dst, k));
			ft_strlcpy(*(dst + k), s + start, i - start + 1);
			k++;
		}
	}
	*(dst + k) = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;

	if (!s)
		return (NULL);
	rtn = (char **)malloc(sizeof(char *) * (ft_cntsize(s, c) + 1));
	if (rtn == NULL)
		return (NULL);
	return (ft_dosplit(rtn, s, c));
}
