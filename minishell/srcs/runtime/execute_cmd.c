/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:42:36 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/22 18:14:11 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../../includes/minishell.h"

static int	is_builtin(char *cmd)
{
	int		rtn;

	rtn = 0;
	if (!ft_strncmp(cmd, "echo", BUFFER_SIZE)
		|| !ft_strncmp(cmd, "pwd", BUFFER_SIZE)
		|| !ft_strncmp(cmd, "cd", BUFFER_SIZE)
		|| !ft_strncmp(cmd, "export", BUFFER_SIZE)
		|| !ft_strncmp(cmd, "unset", BUFFER_SIZE)
		|| !ft_strncmp(cmd, "env", BUFFER_SIZE)
		|| !ft_strncmp(cmd, "exit", BUFFER_SIZE))
		rtn = 1;
	return (rtn);
}

static int	request_single_cmd(t_list **token, t_list *head,
	t_list **env, t_fds *fdinfo)
{
	int		backup_fd[2];
	char	*exitcode_str;

	if (!is_nextpipe_left(*token) && is_builtin((cont_tkn(head)->str2)[0]))
	{
		backup_fd[0] = dup(STDIN_FILENO);
		backup_fd[1] = dup(STDOUT_FILENO);
		dup2(fdinfo->cmd_in_fd, STDIN_FILENO);
		dup2(fdinfo->cmd_out_fd, STDOUT_FILENO);
		exitcode_str = ft_itoa(exec_builtin(cont_tkn(head)->str2, \
			*env, is_nextpipe_left(*token)));
		set_envval(env, "?", exitcode_str);
		free(exitcode_str);
		dup2(backup_fd[0], STDIN_FILENO);
		dup2(backup_fd[1], STDOUT_FILENO);
		ft_close(backup_fd[0]);
		ft_close(backup_fd[1]);
		return (1);
	}
	return (0);
}

pid_t	request_cmd_to_son(t_list **token, t_list *head,
	t_list **env, t_fds *fdinfo)
{
	pid_t	son_pid;

	son_pid = -2;
	if (request_single_cmd(token, head, env, fdinfo) == 0)
		son_pid = fork();
	if (son_pid == -1)
		ft_error_exit("fork failed");
	set_signal(SIG_IGN, SIG_IGN);
	if (son_pid == (pid_t)0)
	{
		set_signal(SIG_DFL, SIG_DFL);
		dup2(fdinfo->cmd_in_fd, STDIN_FILENO);
		dup2(fdinfo->cmd_out_fd, STDOUT_FILENO);
		ft_close(fdinfo->next_cmd_fd);
		if (is_builtin((cont_tkn(head)->str2[0])))
			exit(exec_builtin(cont_tkn(head)->str2, *env, \
				is_nextpipe_left(*token)));
		else
			exec_extern(cont_tkn(head)->str2[0], cont_tkn(head)->str2, *env);
		exit_proc(cont_tkn(head)->str2[0], 1);
	}
	return (son_pid);
}
