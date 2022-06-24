/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minimum_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:08 by hyno              #+#    #+#             */
/*   Updated: 2022/06/20 18:02:30 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

static t_list	*new_minimum_node(char *str, int type, int n)
{
	t_minimum	*rtn;

	rtn = (t_minimum *)malloc(sizeof(t_minimum));
	if (rtn == 0)
		ft_error_exit("malloc failed");
	rtn->minitype = type;
	if (n == 0)
		rtn->ministr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	else
		rtn->ministr = (char *)malloc(sizeof(char) * n);
	if (rtn->ministr == 0)
		ft_error_exit("malloc failed");
	if (n == 0)
		ft_strlcpy(rtn->ministr, str, ft_strlen(str) + 1);
	else
		ft_strlcpy(rtn->ministr, str, n);
	return (ft_lstnew(rtn));
}

static void	get_minimum_node(t_list **root, char **str)
{
	if (**str == '|')
		ft_lstadd_back(root, new_minimum_node("|", PIPE, 0));
	else if (**str == '<' && *(*str + 1) == '<')
		ft_lstadd_back(root, new_minimum_node("<<", HERE, 0));
	else if (**str == '>' && *(*str + 1) == '>')
		ft_lstadd_back(root, new_minimum_node(">>", APPEND, 0));
	else if (**str == '>')
		ft_lstadd_back(root, new_minimum_node(">", OUTPUT, 0));
	else if (**str == '<')
		ft_lstadd_back(root, new_minimum_node("<", INPUT, 0));
	if ((**str == '>' && *(*str + 1) == '>')
		|| (**str == '<' && *(*str + 1) == '<'))
		(*str) += 2;
	else
		(*str) += 1;
}

static int	get_str_node(t_list **root, char **str, t_list **envval)
{
	int		i;
	int		quote_open;

	quote_open = 0;
	i = 0;
	while (!(*(*str + i) == 0 || ((quote_open == 0) && (*(*str + i) == '|' \
		|| *(*str + i) == '<' || *(*str + i) == '>' || *(*str + i) == ' '))))
	{
		if (*(*str + i) == '\'' && quote_open == 0)
			quote_open = 1;
		else if (*(*str + i) == '\"' && quote_open == 0)
			quote_open = 2;
		else if (*(*str + i) == '\'' && quote_open == 1)
			quote_open = 0;
		else if (*(*str + i) == '\"' && quote_open == 2)
			quote_open = 0;
		i++;
	}
	if (quote_open == 1)
		return (ft_error("syntax error: unclosed quote \'", 1, envval, 258));
	else if (quote_open == 2)
		return (ft_error("syntax error: unclosed quote \"", 1, envval, 258));
	(*str) += i;
	ft_lstadd_back(root, new_minimum_node(*str - i, STRING, i + 1));
	return (0);
}

static int	get_minimum_find_error(char	*str, t_list **ev)
{
	if (*str == '|' && *(str + 1) == '|')
		return (ft_error("syntax error: near unexpected token `||'", \
			1, ev, 258));
	if (*str == '<' && *(str + 1) == '>')
		return (ft_error("syntax error: near unexpected token `>'", 1, \
			ev, 258));
	if (*str == '>' && *(str + 1) == '<')
		return (ft_error("syntax error: near unexpected token `<'", 1, \
			ev, 258));
	if ((*str == '>' || *str == '<') && \
		(*(str + 1) == '>' || *(str + 1) == '<') && *(str + 2) == '>')
		return (ft_error("syntax error: near unexpected token '>'", 1, \
			ev, 258));
	if ((*str == '>' || *str == '<') && \
		(*(str + 1) == '>' || *(str + 1) == '<') && *(str + 2) == '<')
		return (ft_error("syntax error: near unexpected token `<'", 1, \
			ev, 258));
	return (0);
}

int	get_minimum(t_list **mini, char *str, t_list **envval)
{
	while (*str)
	{
		if (get_minimum_find_error(str, envval))
			return (1);
		if (*str == ' ')
		{
			str++;
			continue ;
		}
		else if (*str == '|' || *str == '>' || *str == '<')
			get_minimum_node(mini, &str);
		else if (get_str_node(mini, &str, envval))
			return (1);
	}
	return (0);
}
