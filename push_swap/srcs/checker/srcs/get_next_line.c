/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:11:39 by myunkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:06:00 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "checker.h"

ssize_t	ft_findnl(char *s)
{
	ssize_t	rtn;

	rtn = 0;
	while (*(s + rtn) != '\0')
	{
		if (*(s + rtn) == '\n')
			return (rtn);
		rtn++;
	}
	return (-1);
}

char	*ft_stradd(char *s1, char *s2)
{
	char	*rtn;

	if (!s1)
		return (ft_strdup(s2));
	else
	{
		rtn = ft_strjoin(s1, s2);
		free(s1);
		return (rtn);
	}
}

void	ft_putgnl(char **dst, char **src, ssize_t nl_idx)
{
	*(*src + nl_idx) = '\0';
	*dst = ft_strdup(*src);
	ft_memmove(*src, (*src + nl_idx + 1), ft_strlen(*src + nl_idx + 1) + 1);
}

int	ft_checkeof(char **dst, char **src, ssize_t r_size)
{
	ssize_t	nl_idx;

	if (r_size == -1)
		return (-1);
	if (r_size == 0)
	{
		if (*src == NULL)
			*dst = ft_strdup("");
		else
		{
			nl_idx = ft_findnl(*src);
			if (nl_idx >= 0)
			{
				ft_putgnl(dst, src, nl_idx);
				return (1);
			}
			else
				*dst = ft_strdup(*src);
			*src = NULL;
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		nl_idx;
	ssize_t		r_size;
	static char	*rtn[FOPEN_MAX + 1];
	char		*buf;

	if (fd < 0 || !line)
		return (-1);
	buf = malloc(sizeof(char) * 5);
	if (!buf)
		return (-1);
	r_size = read(fd, buf, 4);
	while (r_size > 0)
	{
		*(buf + r_size) = '\0';
		*(rtn + fd) = ft_stradd(*(rtn + fd), buf);
		nl_idx = ft_findnl(*(rtn + fd));
		if (nl_idx >= 0)
		{
			ft_putgnl(line, (rtn + fd), nl_idx);
			free(buf);
			return (1);
		}
	}
	free(buf);
	return (ft_checkeof(line, (rtn + fd), r_size));
}
