/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_waitpid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:49:49 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/22 14:52:03 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "../../includes/minishell.h"

static int	get_exitcode(int status)
{
	int	code;

	if (WIFEXITED(status))
		code = WEXITSTATUS(status);
	else
	{
		code = WTERMSIG(status);
		if (code == SIGQUIT)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
		else if (code == SIGINT)
			ft_putendl_fd("", STDERR_FILENO);
		code = 128 + code;
	}
	return (code);
}

void	exec_waitpid(t_list *rm_pid, t_list **env)
{
	int		status;
	int		exit_code;
	int		qmark_flag;
	char	*exitcode_str;

	if (rm_pid == 0 || *cont_pid(rm_pid) == -2)
		return ;
	exit_code = 0;
	qmark_flag = 1;
	while (rm_pid)
	{
		waitpid(*(pid_t *)rm_pid->content, &status, 0);
		if (qmark_flag == 1)
		{
			exit_code = get_exitcode(status);
			exitcode_str = ft_itoa(exit_code);
			set_envval(env, "?", exitcode_str);
			free(exitcode_str);
			qmark_flag = 0;
		}
		rm_pid = rm_pid->next;
	}
}
