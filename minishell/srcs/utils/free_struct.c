/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:19:38 by hyno              #+#    #+#             */
/*   Updated: 2022/06/17 19:58:20 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

void	free_envval(void *ip)
{
	t_envval	*one;

	one = (t_envval *)ip;
	free(one->key);
	free(one->value);
	free(one);
}

void	free_mini(void *ip)
{
	t_minimum	*one;

	one = (t_minimum *)ip;
	free(one->ministr);
	free(one);
}

void	free_token(void *ip)
{
	t_token	*one;
	char	**temp;

	one = (t_token *)ip;
	temp = one->str2;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(one->str2);
	free(one);
}

void	free_fd(void *ip)
{
	int	*one;

	one = (int *)ip;
	free(one);
	one = NULL;
}

void	free_pid(void *ip)
{
	pid_t	*one;

	one = (pid_t *)ip;
	free(one);
	one = NULL;
}
