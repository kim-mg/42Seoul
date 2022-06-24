/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:03 by hyno              #+#    #+#             */
/*   Updated: 2022/06/22 17:02:32 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	set_envval_use_str(t_list **envval,	char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (BUILTIN);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	if (str[i] == '=')
	{
		str[i] = 0;
		set_envval(envval, str, str + i + 1);
	}
	else if (str[i] == 0)
		return (VALID);
	else
		return (BUILTIN);
	return (VALID);
}	

void	set_envval(t_list **envval, char *key, char *value)
{
	t_envval	*new_env;

	if (search_envval(key, *envval) != 0)
	{
		free(cont_env(search_envval(key, *envval))->value);
		cont_env(search_envval(key, *envval))->value = ft_strdup(value);
		return ;
	}
	new_env = (t_envval *)malloc(sizeof(t_envval));
	if (new_env == 0)
		ft_error_exit("malloc failed");
	new_env->key = (char *)ft_malloc_guard(ft_strdup(key));
	new_env->value = (char *)ft_malloc_guard(ft_strdup(value));
	*envval = ft_lst_addsort(*envval, ft_lstnew(new_env), get_envstr);
}

void	set_default_envval(t_list **envval, char **envp)
{
	set_envval(envval, "?", "0");
	while (*envp)
	{
		set_envval_use_str(&((*envval)->next), *envp);
		envp++;
	}
}

t_list	*search_envval(char *str, t_list *envval)
{
	t_envval	*temp;

	while (envval)
	{
		temp = envval->content;
		if (ft_strncmp(str, temp->key, ft_strlen(str) + 1) == 0)
			return (envval);
		envval = envval->next;
	}
	return (0);
}
