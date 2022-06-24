/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elapse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:52:16 by myunkim           #+#    #+#             */
/*   Updated: 2022/05/20 03:37:46 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../includes/philo.h"

long long	get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	elapse(long long start, long long comp_time)
{
	if (!start)
		start = get_ms();
	while (1)
	{
		if (get_ms() - start >= comp_time)
			break ;
		usleep(100);
	}
}
