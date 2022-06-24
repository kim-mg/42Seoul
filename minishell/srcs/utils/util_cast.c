/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:22:34 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 16:11:45 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*cont_tkn(t_list *list)
{
	return ((t_token *)(list->content));
}

t_envval	*cont_env(t_list *list)
{
	return ((t_envval *)(list->content));
}

t_minimum	*cont_mini(t_list *list)
{
	return ((t_minimum *)(list->content));
}

pid_t	*cont_pid(t_list *list)
{
	return ((pid_t *)(list->content));
}

char	*get_envstr(t_list *envone)
{
	return (((t_envval *)(envone->content))->key);
}
