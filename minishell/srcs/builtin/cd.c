/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:19:23 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 19:58:15 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_cd(char **args, t_list **env)
{
	char	*dir;
	char	*dest;

	if (*(++args) == 0 || **(args) == 0)
		dest = cont_env(search_envval("HOME", *env))->value;
	else
		dest = (*args);
	if (chdir(dest) == -1)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(*args, STDERR_FILENO);
		ft_putstr_fd(": no such file or directory\n", STDERR_FILENO);
		return (BUILTIN);
	}
	set_envval(env, "OLDPWD", get_envval(*env, "PWD"));
	dir = getcwd(0, 0);
	if (!dir)
		return (BUILTIN);
	set_envval(env, "PWD", dir);
	free(dir);
	return (VALID);
}
