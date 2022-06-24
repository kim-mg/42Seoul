/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:50:50 by myunkim           #+#    #+#             */
/*   Updated: 2022/05/20 03:38:04 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_text(t_stat stat)
{
	if (stat == DEAD)
		write(1, " died\n", 6);
	else if (stat == GRAB)
		write(1, " has taken a fork\n", 18);
	else if (stat == EATING)
		write(1, " is eating\n", 11);
	else if (stat == SLEEPING)
		write(1, " is sleeping\n", 13);
	else if (stat == THINKING)
		write(1, " is thinking\n", 13);
}

int	print_line(t_philo *philo, t_stat stat)
{
	pthread_mutex_lock(&philo->c->p);
	if (!philo->c->done)
	{
		ft_putnbr_fd(get_ms() - philo->c->start, 1);
		write(1, " ", 1);
		if (stat == FULL)
			write(1, "success\n", 8);
		else
		{
			ft_putnbr_fd(philo->i + 1, 1);
			print_text(stat);
		}
	}
	if (stat == DEAD || stat == FULL)
		return (0);
	pthread_mutex_unlock(&philo->c->p);
	return (1);
}
