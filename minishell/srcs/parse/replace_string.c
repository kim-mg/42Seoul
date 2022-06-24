/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:19:56 by hyno              #+#    #+#             */
/*   Updated: 2022/06/22 16:58:13 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

static char	*inquote_exe(int inquote, char wd, char **temp_env, t_list *envval)
{
	char	*rtn;

	rtn = 0;
	if ((inquote == 3 || inquote == 4) && !ft_isalnum(wd) && wd != '_')
	{
		if (*temp_env == 0)
			return ("$");
		if (search_envval(*temp_env, envval) != 0)
			rtn = cont_env(search_envval(*temp_env, envval))->value;
		free(*temp_env);
		*temp_env = 0;
	}
	return (rtn);
}

static void	inquote_qmark(int *inquote, char **str, char **rtn, t_list *env)
{
	char	*tempstr;

	while (*inquote != 1 && *(*str) == '$' && (*((*str) + 1) == '?'))
	{
		tempstr = 0;
		tempstr = addstr(tempstr, "?");
		*rtn = addstr(*rtn, inquote_exe(3, 0, &tempstr, env));
		free(tempstr);
		*str += 2;
		if (*inquote == 4)
			*inquote = 2;
		if (*inquote == 3)
			*inquote = 0;
	}
}

static void	inquote_addchar(int inquote, char wd, char **rtn, char **temp_env)
{
	if (inquote == 0 && wd != '\'' && wd != '\"' && wd != '$')
		*rtn = addchar(*rtn, wd);
	if (inquote == 1 && wd != '\'')
		*rtn = addchar(*rtn, wd);
	if (inquote == 2 && wd != '\"' && wd != '$')
		*rtn = addchar(*rtn, wd);
	if (inquote == 3 && !ft_isalnum(wd) && wd != '\'' && \
		wd != '\"' && wd != '$' && wd != '_')
		*rtn = addchar(*rtn, wd);
	if (inquote == 4 && !ft_isalnum(wd) && wd != '\"' && wd != '$' && wd != '_')
		*rtn = addchar(*rtn, wd);
	if (inquote == 3 && (ft_isalnum(wd) || wd == '_'))
		*temp_env = addchar(*temp_env, wd);
	if (inquote == 4 && (ft_isalnum(wd) || wd == '_'))
		*temp_env = addchar(*temp_env, wd);
}

static int	inquote_update(int inquote, char wd)
{
	if (inquote == 0 && wd == '\'')
		return (1);
	if (inquote == 0 && wd == '\"')
		return (2);
	if (inquote == 0 && wd == '$')
		return (3);
	if (inquote == 1 && wd == '\'')
		return (0);
	if (inquote == 2 && wd == '\"')
		return (0);
	if (inquote == 2 && wd == '$')
		return (4);
	if (inquote == 3 && wd == '\'')
		return (1);
	if (inquote == 3 && wd == '\"')
		return (2);
	if (inquote == 3 && !ft_isalnum(wd) && wd != '_' && wd != '$')
		return (0);
	if (inquote == 4 && wd == '\"')
		return (0);
	if (inquote == 4 && !ft_isalnum(wd) && wd != '_' && wd != '$')
		return (2);
	return (inquote);
}

int	*replace_envval(char **str_ori, t_list *envval)
{
	char	*rtn;
	char	*str;
	char	*temp_env;
	int		inquote;

	rtn = 0;
	temp_env = 0;
	str = *str_ori;
	inquote = 0;
	while (1)
	{
		rtn = addstr(rtn, inquote_exe(inquote, *str, &temp_env, envval));
		inquote_qmark(&inquote, &str, &rtn, envval);
		inquote_addchar(inquote, *str, &rtn, &temp_env);
		inquote = inquote_update(inquote, *str);
		if (*str == 0)
			break ;
		str++;
	}
	rtn = addchar(rtn, 0);
	free(*str_ori);
	*str_ori = rtn;
	return (0);
}
