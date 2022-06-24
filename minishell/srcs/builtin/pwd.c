/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:40:43 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:02:45 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_pwd(void)
{
	char	*dir;

	dir = getcwd(0, 0);
	if (!dir)
		return (BUILTIN);
	ft_putstr_fd(dir, 1);
	ft_putstr_fd("\n", 1);
	free(dir);
	return (VALID);
}
