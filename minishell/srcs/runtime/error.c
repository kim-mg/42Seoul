/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:32 by hyno              #+#    #+#             */
/*   Updated: 2022/06/20 18:02:25 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

int	ft_error(char *message, int error_flag, t_list **envval, int exitcode)
{
	free(((t_envval *)((*envval)->content))->value);
	((t_envval *)((*envval)->content))->value = ft_itoa(exitcode);
	if (message)
	{
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	return (error_flag);
}

void	ft_error_exit(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
}

void	*ft_malloc_guard(void *arg)
{
	if (arg == 0)
		ft_error_exit("malloc failed");
	return (arg);
}
