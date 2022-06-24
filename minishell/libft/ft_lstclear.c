/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:13:13 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:13:14 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr2;

	if (lst != 0 && del != 0)
	{
		ptr = *lst;
		while (ptr)
		{
			del(ptr->content);
			ptr2 = ptr;
			ptr = ptr->next;
			free(ptr2);
		}
		*lst = 0;
	}
}
