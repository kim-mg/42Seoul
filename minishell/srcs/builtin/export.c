/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:19:07 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 19:03:48 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	export_simpleprint(t_list *envval)
{
	while (envval)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd((cont_env(envval)->key), STDOUT_FILENO);
		ft_putstr_fd(("=\""), STDOUT_FILENO);
		ft_putstr_fd((cont_env(envval)->value), STDOUT_FILENO);
		ft_putstr_fd(("\"\n"), STDOUT_FILENO);
		envval = envval->next;
	}
	return (VALID);
}

int	builtin_export(char **args, t_list **envval)
{
	int	exit_code;

	if (*(++args) == 0)
		return (export_simpleprint((*envval)->next));
	while (*args)
	{
		exit_code = set_envval_use_str(envval, *args);
		if (exit_code == 1)
		{
			ft_putstr_fd("export: '", STDERR_FILENO);
			ft_putstr_fd(*args, STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		(args)++;
	}
	return (exit_code);
}
