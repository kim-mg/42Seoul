/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:33:02 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:02:35 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/minishell.h"

void	print_echo(char **args, int flag)
{
	int	i;

	if (args[0] == NULL)
	{
		write(1, "\n", STDOUT_FILENO);
		return ;
	}
	i = 0;
	ft_putstr_fd(args[i], STDOUT_FILENO);
	while (args[++i])
	{
		write(1, " ", 1);
		ft_putstr_fd(args[i], STDOUT_FILENO);
	}
	if (!flag)
		write(1, "\n", 1);
}

int	builtin_echo(char **args)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	while (args[++i])
	{
		j = 0;
		if (args[i][j] != '-')
			break ;
		while (args[i][++j] == 'n')
			;
		if (args[i][j] != '\0')
			break ;
		flag = 1;
	}
	print_echo(&args[i], flag);
	return (VALID);
}
