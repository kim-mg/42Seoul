/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:24:36 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:09:29 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*ft_lst_addsort(t_list *src, t_list *newone,
	char *(*get_str)(t_list *))
{
	t_list	*head;
	t_list	*before;
	t_list	*rtn;

	if (src == 0)
		return (newone);
	rtn = src;
	before = 0;
	head = src;
	while (head)
	{
		if (ft_strncmp(get_str(head), get_str(newone), 2147483647) > 0)
			break ;
		before = head;
		head = head->next;
	}
	if (before == 0)
		rtn = newone;
	else
		before->next = newone;
	newone->next = head;
	return (rtn);
}

void	ft_lstremove(t_list **lst, t_list *target, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;
	t_list	*rtn;

	rtn = 0;
	head = *lst;
	while (head)
	{
		if (head == target)
		{
			head = head->next;
			ft_lstdelone(target, del);
			continue ;
		}
		temp = head;
		head = head->next;
		temp->next = 0;
		ft_lstadd_back(&rtn, temp);
	}
	if (rtn)
		ft_lstlast(rtn)->next = 0;
	*lst = rtn;
}

void	ft_lstadd_int(t_list **lst, int *i)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew((void *)i);
	if (!new)
		ft_error_exit("rdr error: list malloc failed");
	ft_lstadd_back(lst, new);
}

pid_t	*new_pidone(pid_t arg)
{
	pid_t	*rtn;

	if (ft_calloc((void *)&rtn, sizeof(pid_t *), 1) == -1)
		ft_error_exit("malloc failed");
	*rtn = arg;
	return (rtn);
}

int	*new_intone(int arg)
{
	int	*rtn;

	if (ft_calloc((void *)&rtn, sizeof(int *), 1) == -1)
		ft_error_exit("malloc failed");
	*rtn = arg;
	return (rtn);
}
