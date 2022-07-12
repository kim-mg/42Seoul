#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>

int	ft_strlen(char *s)
{
	char	*t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

char	*ft_strdup(char *s)
{
	char	*rtn;
	int	i;

	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(rtn + i) = *(s + i);
		i++;
	}
	*(rtn + i) = '\0';
	return (rtn);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rtn;
	int	i;
	int	j;

	if (!s1)
	{
		rtn = ft_strdup(s2);
		return (rtn);
	}
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(rtn + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(rtn + i) = *(s2 + j);
		j++;
		i++;
	}
	*(rtn + i) = '\0';
	return (rtn);
}

int	find_nl(char *s)
{
	int	i;

	// if (!s)
	// 	return (-1);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(char **sto, int nl_idx)
{
	char	*line;
	char	*tmp;
	char	*backup;
	int	i;

	line = (char *)malloc(sizeof(char) * (nl_idx + 1 + 1));
	if (!line)
		return (NULL);
	tmp = *sto;
	i = 0;
	while (i < nl_idx + 1)
	{
		*(line + i) = *(tmp + i);
		i++;
	}
	*(line + i) = '\0';
	backup = NULL;
	if (*(tmp + i))
		backup = ft_strdup(tmp + i);
	free(*sto);
	*sto = backup;
	return (line);
}

char	*check_eof(char **sto, int r_size)
{
	char	*line;
	int	nl_idx;

	if (r_size == -1)
		return (NULL);
	else
	{
		if (!(*sto))
			return (NULL);
		else
		{
			line = NULL;
			nl_idx = find_nl(*sto);
			if (nl_idx >= 0)
				return (get_line(sto, nl_idx));
			line = ft_strdup(*sto);
			free(*sto);
			*sto = NULL;
			return (line);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*sto;
	char	*tmp;
	char	*buf;
	int	r_size;
	int	nl_idx;

	(void)tmp;
	(void)nl_idx;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r_size = read(fd, buf, BUFFER_SIZE);
	while (r_size > 0)
	{
		tmp = NULL;
		*(buf + r_size) = '\0';
		tmp = ft_strjoin(sto, buf);
		free(sto);
		sto = tmp;
		// sto = ft_strjoin(sto, buf);
		nl_idx = -1;
		if (BUFFER_SIZE > 100)
			nl_idx = find_nl(sto);
		if (nl_idx >= 0)
		{
			free(buf);
			return (get_line(&sto, nl_idx));
		}
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (check_eof(&sto, r_size));
}
