/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:28 by hyno              #+#    #+#             */
/*   Updated: 2022/06/20 18:03:45 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token	*new_token(int type, int row)
{
	t_token	*new_token;

	new_token = 0;
	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == 0)
		ft_error_exit("malloc failed");
	new_token->tokentype = type;
	new_token->str2 = 0;
	new_token->str2 = (char **)malloc(sizeof(char *) * (row + 1));
	if (new_token->str2 == 0)
		ft_error_exit("malloc failed");
	(new_token->str2)[row] = 0;
	return (new_token);
}

static void	get_token_redi_add(t_list **token, t_list **mini, t_list *rm_place)
{
	t_token	*rtn;

	rtn = new_token(cont_mini(rm_place)->minitype, 2);
	rtn->str2[0] = \
		ft_malloc_guard(ft_strdup(cont_mini(rm_place)->ministr));
	if (cont_mini(rm_place)->minitype >= OUTPUT)
		rtn->str2[1] = ft_malloc_guard(\
			ft_strdup((cont_mini(rm_place->next))->ministr));
	if (cont_mini(rm_place)->minitype >= OUTPUT)
		ft_lstremove(mini, rm_place->next, free_mini);
	if (cont_mini(rm_place)->minitype == PIPE)
		rtn->str2[1] = 0;
	ft_lstremove(mini, rm_place, free_mini);
	ft_lstadd_back(token, ft_malloc_guard(ft_lstnew(rtn)));
}

static int	get_token_redi(t_list **token, t_list **mini, t_list **envval)
{
	t_list	*mini_header;

	mini_header = *mini;
	while (mini_header)
	{
		if ((cont_mini(mini_header)->minitype >= OUTPUT && \
		cont_mini(mini_header)->minitype <= HERE) || \
		cont_mini(mini_header)->minitype == PIPE)
			break ;
		mini_header = mini_header->next;
	}
	if (mini_header == 0 || cont_mini(mini_header)->minitype == PIPE)
		return (0);
	if (mini_header->next == 0 || \
	cont_mini(mini_header->next)->minitype != STRING)
		return (get_token_redi_error(cont_mini(mini_header)->minitype, \
			envval));
	get_token_redi_add(token, mini, mini_header);
	return (2);
}

static int	get_token_cmd(t_list **token, t_list **mini, t_list **envval)
{
	t_list	*head;
	t_list	*temp;
	t_token	*rtn;
	int		size;

	size = 0;
	head = *mini;
	while ((++size) && head && cont_mini(head)->minitype != PIPE)
		head = head->next;
	if ((--size) == 0)
		return (ft_error("syntax error: command not found", 1, envval, 258));
	rtn = new_token(CMD, size);
	size = 0;
	head = *mini;
	while (head && cont_mini(head)->minitype != PIPE)
	{
		rtn->str2[size] = ft_malloc_guard(ft_strdup(cont_mini(head)->ministr));
		temp = head->next;
		ft_lstremove(mini, head, free_mini);
		head = temp;
		size++;
	}
	ft_lstadd_back(token, ft_malloc_guard(ft_lstnew(rtn)));
	return (0);
}

int	get_token(t_list **token, t_list **mini, t_list **envval)
{
	int	i;

	while (1)
	{
		i = get_token_redi(token, mini, envval);
		if (i == 2)
			continue ;
		else if (i == 1)
			return (1);
		if (get_token_cmd(token, mini, envval))
			return (1);
		if (*mini != 0)
			get_token_redi_add(token, mini, *mini);
		else
			break ;
	}
	return (0);
}
