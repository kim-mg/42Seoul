/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:13:45 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:13:45 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strnum(const char *s, char c, int n)
{
	int	rtn;
	int	i;

	i = 0;
	rtn = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (n >= 0 && n == rtn)
			return (i);
		if (s[i] != 0)
			rtn++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (rtn);
}

char	*get_str(const char *s, char c, int n)
{
	int		i;
	char	*rtn;

	i = 0;
	while (s[i + n] != c && s[i + n] != 0)
		i++;
	rtn = malloc(i + 1);
	if (rtn == 0)
		return (0);
	i = 0;
	while (s[i + n] != c && s[i + n] != 0)
	{
		rtn[i] = s[i + n];
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}

void	free_deadman(char **rtn, int i)
{
	i--;
	while (i >= 0)
	{
		free(rtn[i]);
		i--;
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**rtn;

	rtn = malloc(sizeof(char *) * (count_strnum(s, c, -1) + 1));
	if (rtn == 0)
		return (0);
	i = 0;
	while (i < count_strnum(s, c, -1))
	{
		rtn[i] = get_str(s, c, count_strnum(s, c, i));
		if (rtn[i] == 0)
		{
			free_deadman(rtn, i);
			free(rtn);
			return (0);
		}
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
