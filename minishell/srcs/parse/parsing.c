/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:22 by hyno              #+#    #+#             */
/*   Updated: 2022/06/22 16:36:37 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	mre_free(t_list **temp)
{
	free_mini(cont_env(*temp));
	free(*temp);
	*temp = 0;
}

static int	has_quote(char *str)
{
	int	rtn;

	rtn = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			rtn = 1;
		str++;
	}
	return (rtn);
}

static int	*minimum_replace_envval(t_list **mini, t_list *envval)
{
	t_list		*rtn;
	t_list		*head;
	t_list		*temp;
	int			hasquote;

	rtn = 0;
	head = *mini;
	while (head)
	{
		hasquote = has_quote(cont_mini(head)->ministr);
		if (cont_mini(head)->minitype == STRING)
			replace_envval(&cont_mini(head)->ministr, envval);
		temp = head;
		head = head->next;
		temp->next = 0;
		if (!hasquote && (cont_mini(temp)->ministr == NULL || \
			(cont_mini(temp)->ministr)[0] == 0))
			mre_free(&temp);
		else
			ft_lstadd_back(&rtn, temp);
	}
	*mini = rtn;
	return (0);
}

int	parsing(t_list **token, char *str, t_list **envval)
{
	t_list	*mini;

	mini = 0;
	if (get_minimum(&mini, str, envval))
	{
		ft_lstclear(&mini, free_mini);
		return (1);
	}
	minimum_replace_envval(&mini, *envval);
	if (mini == 0)
		return (1);
	if (get_token(token, &mini, envval))
	{
		ft_lstclear(&mini, free_mini);
		ft_lstclear(token, free_token);
		return (1);
	}
	return (0);
}
