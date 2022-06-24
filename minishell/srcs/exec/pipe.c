/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:06:45 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:03:27 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include "../../includes/minishell.h"

void	exec_pipe(t_fds *fdinfo)
{
	int	pipe_fd[2];

	pipe(pipe_fd);
	fdinfo->cmd_out_fd = pipe_fd[1];
	fdinfo->next_cmd_fd = pipe_fd[0];
}

int	is_nextpipe_left(t_list *head)
{
	int	is;

	is = 0;
	head = head->next;
	while (head)
	{
		if (cont_tkn(head)->tokentype == PIPE)
			is = 1;
		head = head->next;
	}
	return (is);
}
