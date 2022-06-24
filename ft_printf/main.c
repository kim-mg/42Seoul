/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 22:57:25 by myunkim           #+#    #+#             */
/*   Updated: 2021/06/30 02:19:26 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	const char	*s;
	int	i;

	s = "[%-05c]";
	i = printf(s, 'c');
	printf("\n%d\n", i);

	i = ft_printf(s, 'c');
	printf("\n%d\n", i);
	return (0);
}
