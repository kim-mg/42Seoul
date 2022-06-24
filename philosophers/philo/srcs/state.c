/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:51:31 by myunkim           #+#    #+#             */
/*   Updated: 2022/05/20 03:41:17 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->c->f[philo->l_f]);
	pthread_mutex_lock(&philo->c->f[philo->r_f]);
	print_line(philo, GRAB);
	print_line(philo, GRAB);
}

static void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->c->f[philo->l_f]);
	pthread_mutex_unlock(&philo->c->f[philo->r_f]);
}

void	philo_eat(t_philo *philo)
{
	take_fork(philo);
	print_line(philo, EATING);
	philo->cur_time = get_ms();
	++(philo->n_eat);
	elapse(0, philo->c->time_eat);
	if (philo->c->req_eat && philo->n_eat == philo->c->req_eat)
		++(philo->c->full);
	put_fork(philo);
}

void	philo_sleep(t_philo *philo)
{
	print_line(philo, SLEEPING);
	elapse(0, philo->c->time_sleep);
}

void	philo_think(t_philo *philo)
{
	print_line(philo, THINKING);
}
