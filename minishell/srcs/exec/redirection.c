/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:04:40 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 20:22:15 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../includes/minishell.h"

static int	set_fdinfo(t_token *token, int *old_fd, t_list **rdr_fd)
{
	int		*new_fd;

	if (ft_calloc((void **)&new_fd, sizeof(int), 1) == -1)
		ft_error_exit("rdr error: fd malloc failed");
	if (token->tokentype == INPUT)
		*new_fd = exec_redir_input(token->str2[1]);
	else if (token->tokentype == OUTPUT)
		*new_fd = exec_redir_output(token->str2[1]);
	else if (token->tokentype == APPEND)
		*new_fd = exec_redir_append(token->str2[1]);
	else if (token->tokentype == HERE)
		*new_fd = exec_redir_heredoc(token->str2[1]);
	ft_close(*old_fd);
	*old_fd = *new_fd;
	ft_lstadd_int(rdr_fd, new_fd);
	if (*new_fd == -1)
		return (1);
	return (0);
}

int	exec_redir(t_list *token, t_fds *fdinfo, t_list **envval)
{
	int		rtn;
	t_token	*to;
	char	*rtn_str;

	rtn = 0;
	to = cont_tkn(token);
	if (to->tokentype == INPUT || to->tokentype == HERE)
		rtn = set_fdinfo(to, &fdinfo->cmd_in_fd, &fdinfo->rdr_fd);
	else if (to->tokentype == OUTPUT || to->tokentype == APPEND)
		rtn = set_fdinfo(to, &fdinfo->cmd_out_fd, &fdinfo->rdr_fd);
	if (rtn)
	{
		errno = ENOENT;
		exit_proc(to->str2[1], 0);
		rtn_str = ft_itoa(rtn);
		set_envval(envval, "?", rtn_str);
		free(rtn_str);
	}
	return (rtn);
}
