/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:29:04 by hyno              #+#    #+#             */
/*   Updated: 2022/06/22 18:08:00 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../includes/minishell.h"

void	exit_proc(char *entry, int exit_flag)
{
	int	exit_code;

	exit_code = VALID;
	if (errno)
		ft_putstr_fd(entry, STDERR_FILENO);
	if (errno == ENOENT)
	{
		ft_putendl_fd(": No search file or directory", STDERR_FILENO);
		exit_code = NOTFOUND;
	}
	if (errno == EFAULT)
	{
		ft_putendl_fd(": Command not found", STDERR_FILENO);
		exit_code = NOTFOUND;
	}
	if (errno == EACCES)
	{
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
		exit_code = NOTEXEC;
	}
	if (exit_flag)
		exit(exit_code);
}
