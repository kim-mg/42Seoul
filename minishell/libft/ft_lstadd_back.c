/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:13:08 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:13:08 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst != 0 || new != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			ptr = *lst;
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new;
		}
	}
}
