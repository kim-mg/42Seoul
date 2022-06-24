/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:35:37 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:03:30 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include "../../includes/minishell.h"

int	exec_redir_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, S_IRWXU | S_IRGRP | S_IROTH);
	if (fd < 1)
		return (-1);
	return (fd);
}

int	exec_redir_output(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP | S_IROTH);
	if (fd < 1)
		return (-1);
	return (fd);
}

int	exec_redir_append(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
	if (fd < 1)
		return (-1);
	return (fd);
}

int	exec_redir_heredoc(char *eof)
{
	int		fd;
	char	*input;

	echoctl_off();
	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 1)
		return (-1);
	while (1)
	{
		input = readline("> ");
		if (!input || !ft_strncmp(eof, input, BUFFER_SIZE))
		{
			free(input);
			break ;
		}
		ft_putendl_fd(input, fd);
		free(input);
	}
	close(fd);
	fd = open(".heredoc", O_RDWR, S_IRWXU);
	if (fd < 1)
		return (-1);
	return (fd);
}
