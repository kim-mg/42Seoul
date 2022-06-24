/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:18:58 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/22 17:28:22 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_unset(char **args, t_list **envval)
{
	int	i;
	int	exit_code;

	while (*args)
	{
		i = 0;
		exit_code = VALID;
		if (!ft_isalpha((*args)[i]) && (*args)[i] != '_')
			exit_code = BUILTIN;
		while (ft_isalnum((*args)[i]) || (*args)[i] == '_')
			i++;
		if ((*args)[i] && !ft_isalnum((*args)[i]) && (*args)[i] != '_')
			exit_code = BUILTIN;
		if (exit_code == BUILTIN)
		{
			ft_putstr_fd("unset: '", STDERR_FILENO);
			ft_putstr_fd(*args, STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		else if (exit_code == VALID)
			ft_lstremove(envval, search_envval(*args, *envval), free_envval);
		args++;
	}
	return (exit_code);
}
