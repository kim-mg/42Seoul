/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:20:58 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/22 18:11:50 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include "../../includes/minishell.h"

char	*get_envval(t_list *env, char *comp)
{
	while (env)
	{
		if (!ft_strncmp(comp, cont_env(env)->key, BUFFER_SIZE))
			return (cont_env(env)->value);
		env = env->next;
	}
	return (NULL);
}

static int	check_dir(char *cmd, char *path, DIR *dir)
{
	int				rtn;
	char			*abs_path;
	struct stat		info;
	struct dirent	*file;

	rtn = 0;
	file = readdir(dir);
	while (file)
	{
		if (!ft_strncmp(cmd, file->d_name, BUFFER_SIZE))
		{
			abs_path = ft_strjoin(ft_strjoin(path, "/"), file->d_name);
			if (lstat(abs_path, &info) != -1)
				if (info.st_mode & S_IXUSR)
					rtn = 1;
		}
		file = readdir(dir);
	}
	if (rtn)
		closedir(dir);
	return (rtn);
}

static char	*get_path(char *cmd, char *env_path)
{
	char	**path;
	DIR		*dir;

	path = ft_split(env_path, ':');
	while (*path)
	{
		dir = opendir(*path);
		if (dir == NULL)
		{
			path++;
			continue ;
		}
		if (check_dir(cmd, *path, dir))
			break ;
		closedir(dir);
		path++;
	}
	return (*path);
}

char	*find_cmd(char *cmd, t_list *env)
{
	char	*path;
	char	*env_path;

	env_path = NULL;
	if (get_envval(env, "PATH") != NULL)
		env_path = ft_strdup(get_envval(env, "PATH"));
	if (env_path == NULL)
	{
		errno = ENOENT;
		exit_proc(cmd, 1);
	}
	path = get_path(cmd, env_path);
	if (path)
		return (ft_strjoin(ft_strjoin(path, "/"), cmd));
	else
	{
		errno = EFAULT;
		exit_proc(cmd, 1);
	}
	return (NULL);
}
