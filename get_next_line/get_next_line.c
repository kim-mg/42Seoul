/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:35:08 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/02 00:35:51 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

ssize_t	ft_findnl(char *s)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	get_info(char **fd, t_info *info)
{
	char	*tmp;

	info->a_size = BUFFER_SIZE;
	if (BUFFER_SIZE < 100)
		info->a_size = 100;
	if (!(*fd))
	{
		*fd = ft_strndup(info->buf, info->a_size);
		info->sto_size = info->r_size;
		info->aloc_size = info->a_size;
	}
	else
	{
		if (info->sto_size + info->r_size > info->aloc_size)
		{
			tmp = ft_strjoin_gnl(*fd, info->buf, info);
			info->aloc_size += info->a_size;
			free(*fd);
			*fd = tmp;
		}
		else
			ft_strlcat_gnl(*fd, info->buf, info->r_size + 1, info);
		info->sto_size += info->r_size;
	}
}

char	*get_line(char **sto, t_info *info)
{
	char	*line;
	char	*tmp;
	char	*backup;
	int		i;

	line = malloc(sizeof(char) * (info->nl_idx + 1 + 1));
	if (!line)
		return (NULL);
	tmp = *sto;
	i = -1;
	while (++i <= (int)info->nl_idx)
		*(line + i) = *(tmp + i);
	*(line + i) = '\0';
	info->sto_size -= info->nl_idx + 1;
	if (info->sto_size / info->a_size == 0 || info->sto_size % info->a_size > 0)
		info->aloc_size = ((info->sto_size / info->a_size) + 1) * info->a_size;
	else
		info->aloc_size = ((info->sto_size / info->a_size)) * info->a_size;
	backup = NULL;
	if (*(tmp + i))
		backup = ft_strndup(tmp + i, info->aloc_size);
	free(*sto);
	*sto = backup;
	return (line);
}

char	*check_eof(char	**sto, t_info *info)
{
	char	*line;

	if (info->r_size == -1)
		return (NULL);
	if (info->r_size == 0)
	{
		if (!(*sto))
			return (NULL);
		else
		{
			line = NULL;
			info->nl_idx = ft_findnl(*sto);
			if (info->nl_idx >= 0)
				return (get_line(sto, info));
			if (**sto)
				line = ft_strndup(*sto, (int)info->sto_size);
			free(*sto);
			*sto = NULL;
			return (line);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_info	info;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	info.buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!info.buf)
		return (NULL);
	info.r_size = read(fd, info.buf, BUFFER_SIZE);
	while (info.r_size > 0)
	{
		*(info.buf + info.r_size) = '\0';
		get_info((info.sto + fd), &info);
		info.nl_idx = -1;
		if (BUFFER_SIZE > 1)
			info.nl_idx = ft_findnl(*(info.sto + fd));
		if (info.nl_idx >= 0)
		{
			free(info.buf);
			return (get_line(info.sto + fd, &info));
		}
		info.r_size = read(fd, info.buf, BUFFER_SIZE);
	}
	free(info.buf);
	return (check_eof(info.sto + fd, &info));
}
