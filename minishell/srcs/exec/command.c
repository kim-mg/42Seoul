/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:11:44 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/22 18:01:22 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_builtin(char **args, t_list *env, int pipe_flag)
{
	if (!ft_strncmp(args[0], "echo", BUFFER_SIZE))
		return (builtin_echo(args));
	else if (!ft_strncmp(args[0], "pwd", BUFFER_SIZE))
		return (builtin_pwd());
	else if (!ft_strncmp(args[0], "cd", BUFFER_SIZE))
		return (builtin_cd(args, &env));
	else if (!ft_strncmp(args[0], "export", BUFFER_SIZE))
		return (builtin_export(args, &env));
	else if (!ft_strncmp(args[0], "unset", BUFFER_SIZE))
		return (builtin_unset(args, &env));
	else if (!ft_strncmp(args[0], "env", BUFFER_SIZE))
		return (builtin_env(&env));
	else if (!ft_strncmp(args[0], "exit", BUFFER_SIZE))
		return (builtin_exit(args, pipe_flag));
	(void)pipe_flag;
	return (BUILTIN);
}

static int	envp_len(t_list *env)
{
	int	rtn;

	rtn = 0;
	while (env)
	{
		rtn++;
		env = env->next;
	}
	return (rtn);
}

static char	**make_envp(t_list *env)
{
	char	**envp;
	char	*key;
	int		i;

	if (ft_calloc((void **)&envp, sizeof(char *), (envp_len(env) + 1)))
		exit(1);
	i = 0;
	while (env)
	{
		if (!ft_strncmp("?", cont_env(env)->key, BUFFER_SIZE))
		{
			env = env->next;
			continue ;
		}
		key = ft_strjoin(cont_env(env)->key, "=");
		envp[i] = ft_strjoin(key, cont_env(env)->value);
		i++;
		env = env->next;
	}
	return (envp);
}

void	exec_extern(char *cmd, char **args, t_list *env)
{
	char	*path;
	char	**env_path;

	env_path = make_envp(env);
	if (*cmd == '.' || *cmd == '/')
		path = ft_strdup(cmd);
	else
		path = find_cmd(ft_strdup(cmd), env);
	execve(path, args, env_path);
}
