/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:08:41 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/22 16:33:40 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../../includes/minishell.h"

static void	execute_init(t_list **rm_pid, t_list **token, \
		t_list **head, t_fds *fdinfo)
{
	*rm_pid = 0;
	*head = *token;
	echoctl_on();
	fdinfo->rdr_fd = NULL;
	fdinfo->next_cmd_fd = STDIN_FILENO;
}

static void	close_current_fds(t_fds *fdinfo)
{
	ft_close(fdinfo->cmd_in_fd);
	ft_close(fdinfo->cmd_out_fd);
	fdinfo->cmd_in_fd = fdinfo->next_cmd_fd;
}

static void	free_exit(t_fds *fdinfo, t_list **rm_pid)
{
	t_list	*temp;

	temp = fdinfo->rdr_fd;
	while (temp)
	{
		close(*(int *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(rm_pid, free_pid);
	ft_lstclear(&fdinfo->rdr_fd, free_fd);
}

static int	execute_rediloop(t_list **env, t_list **head, t_fds *fdinfo)
{
	while (cont_tkn(*head)->tokentype >= OUTPUT
		&& cont_tkn(*head)->tokentype <= HERE)
	{
		if (exec_redir(*head, fdinfo, env) != 0)
		{
			while (*head && cont_tkn(*head)->tokentype != PIPE)
				*head = (*head)->next;
			return (-1);
		}
		*head = (*head)->next;
	}
	return (0);
}

void	execute(t_list **token, t_list **env)
{
	t_list	*head;
	t_list	*rm_pid;
	t_fds	fdinfo;

	execute_init(&rm_pid, token, &head, &fdinfo);
	while (head)
	{
		close_current_fds(&fdinfo);
		if (cont_tkn(head)->tokentype == PIPE)
			head = head->next;
		if (is_nextpipe_left(head))
			exec_pipe(&fdinfo);
		else
			fdinfo.cmd_out_fd = STDOUT_FILENO;
		if (execute_rediloop(env, &head, &fdinfo) == -1)
			continue ;
		ft_lstadd_front(&rm_pid, ft_malloc_guard(ft_lstnew \
			(new_pidone(request_cmd_to_son(token, head, env, &fdinfo)))));
		head = head->next;
	}
	close_current_fds(&fdinfo);
	exec_waitpid(rm_pid, env);
	free_exit(&fdinfo, &rm_pid);
	set_signal(sigint_handler, SIG_IGN);
	echoctl_off();
}
