/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:49:10 by hyno              #+#    #+#             */
/*   Updated: 2022/06/20 18:03:38 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_token_redi_error(int minitype, t_list **envval)
{
	if (minitype == INPUT)
		return (ft_error("syntax error: cant' find argument for '<'", \
			1, envval, 258));
	else if (minitype == OUTPUT)
		return (ft_error("syntax error: cant' find argument for '>'", \
			1, envval, 258));
	else if (minitype == APPEND)
		return (ft_error("syntax error: cant' find argument for '>>'", \
			1, envval, 258));
	else if (minitype == HERE)
		return (ft_error("syntax error: cant' find argument for '<<'", \
			1, envval, 258));
	return (0);
}
