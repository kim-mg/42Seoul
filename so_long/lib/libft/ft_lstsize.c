/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:00:27 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/20 20:07:09 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	rtn;

	if (!lst)
		return (0);
	rtn = 1;
	while (lst->next != NULL)
	{
		rtn++;
		lst = lst->next;
	}
	return (rtn);
}
