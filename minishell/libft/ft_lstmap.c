/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:13:23 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:13:23 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rtn;
	t_list	*ptr;

	if (lst == 0 || f == 0)
		return (0);
	ptr = malloc(sizeof(t_list));
	rtn = ptr;
	while (lst)
	{
		if (ptr == 0)
		{
			ft_lstclear(&rtn, del);
			return (0);
		}
		ptr->content = f(lst->content);
		lst = lst->next;
		if (lst == 0)
			break ;
		ptr->next = malloc(sizeof(t_list));
		ptr = ptr->next;
	}
	ptr->next = 0;
	return (rtn);
}
