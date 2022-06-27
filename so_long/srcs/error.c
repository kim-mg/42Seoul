/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:06:07 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/23 03:01:59 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../lib/libft/libft.h"

void	error_exit(char *err)
{
	size_t	size;

	size = ft_strlen(err);
	write(2, "Error >> ", 9);
	write(2, err, size);
	write(2, "\n", 1);
	exit(1);
}
