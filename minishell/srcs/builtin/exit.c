/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:36:12 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/22 15:12:11 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

static void	numeric_exit(char *entry)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(entry, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	exit(OUTRANGE);
}

static void	sign_check(char **line)
{
	char	*temp;

	temp = *line;
	if (temp && *temp == '-')
	{
		temp++;
		*line = temp;
	}
}

static int	flow_check(char *line)
{
	if (ft_strlen(line) > 2 && (ft_atoi(line) == 0 || ft_atoi(line) == -1))
		return (1);
	return (0);
}

int	builtin_exit(char **args, int pipe_flag)
{
	int		rtn;
	char	*exit_code;

	rtn = 0;
	exit_code = *(args + 1);
	sign_check(&exit_code);
	while (exit_code && *exit_code)
		if (!ft_isdigit(*exit_code++))
			rtn = 1;
	if (pipe_flag == 0)
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (rtn || (*(args + 1) && !ft_strncmp("-", *(args + 1), BUFFER_SIZE)))
		numeric_exit(*(args + 1));
	else if (!rtn && *(args + 1) && *(args + 2))
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		return (BUILTIN);
	}
	if (*(args + 1) && flow_check(*(args + 1)))
		numeric_exit(*(args + 1));
	if (*(args + 1))
		rtn = ft_atoi(*(args + 1));
	exit(rtn);
}
