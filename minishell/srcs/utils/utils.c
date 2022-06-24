/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:57:46 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/20 18:09:22 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

int	ft_calloc(void **ptr, size_t m_size, size_t n)
{
	*ptr = malloc(m_size * n);
	if (!*ptr)
		return (-1);
	ft_memset(*ptr, 0, m_size * n);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	ft_close(int fd)
{
	if (fd >= 2)
		close(fd);
}
