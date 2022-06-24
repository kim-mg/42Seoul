/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:19:16 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:02:38 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_env(t_list **envval)
{
	t_list	*head;

	head = (*envval)->next;
	while (head)
	{
		ft_putstr_fd(((t_envval *)(head->content))->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putstr_fd(((t_envval *)(head->content))->value, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		head = head->next;
	}
	return (VALID);
}
