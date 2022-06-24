/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 03:08:06 by myunkim           #+#    #+#             */
/*   Updated: 2021/05/19 18:06:44 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	cnt;

	if (!s)
		return ;
	cnt = ft_strlen(s);
	write(fd, s, cnt);
	write(fd, "\n", sizeof(char));
}
