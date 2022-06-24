/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:07:35 by myunkim           #+#    #+#             */
/*   Updated: 2022/05/20 03:46:10 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	die_checker(t_cond *c, t_philo *philo)
{
	int	i;

	elapse(0, c->time_die - 100);
	while (1)
	{
		i = -1;
		while (++i < c->num_of_philo)
		{
			if (c->req_eat && c->full >= c->num_of_philo)
			{
				print_line(&philo[i], FULL);
				c->done = 1;
				return ;
			}
			if (get_ms() - philo[i].cur_time > c->time_die)
			{
				print_line(&philo[i], DEAD);
				c->done = 1;
				return ;
			}
		}
	}
}
