/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:43:15 by myunkim           #+#    #+#             */
/*   Updated: 2022/05/20 03:44:57 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/philo.h"

static int	set_conditions(int ac, char **av, t_cond *c)
{
	if (ac < 4 || ac > 5)
		return (error_exit("arg has not satisfied.", c, NULL));
	c->num_of_philo = ft_atoi(av[1]);
	c->time_die = ft_atoi(av[2]);
	c->time_eat = ft_atoi(av[3]);
	c->time_sleep = ft_atoi(av[4]);
	if (ac == 5)
		c->req_eat = ft_atoi(av[5]);
	if (c->num_of_philo < 1 || c->time_die < 1 || c->time_eat < 1
		|| c->time_sleep < 1 || c->req_eat < 0)
		return (error_exit("args must be natural number.", c, NULL));
	return (1);
}

static int	set_proc(int ac, char **av, t_cond *c, t_philo **philo)
{
	int	i;

	memset(c, 0, sizeof(t_cond));
	*philo = NULL;
	if (!set_conditions(--ac, av, c))
		return (0);
	*philo = malloc(c->num_of_philo * sizeof(t_philo));
	if (!(*philo))
		return (error_exit("philo alloc failed.", c, philo));
	c->f = malloc(c->num_of_philo * sizeof(pthread_mutex_t));
	if (!c->f)
		return (error_exit("mutex alloc failed.", c, philo));
	memset(*philo, 0, c->num_of_philo * sizeof(t_philo));
	memset(c->f, 0, c->num_of_philo * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < c->num_of_philo)
		if (pthread_mutex_init(&c->f[i], NULL))
			return (error_exit("mutex init failed.", c, philo));
	if (pthread_mutex_init(&c->p, NULL))
		return (error_exit("mutex init failed.", c, philo));
	return (1);
}

static void	*cycle(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static int	run_philo(t_cond *c, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < c->num_of_philo)
	{
		philo[i].c = c;
		philo[i].i = i;
		philo[i].l_f = i;
		philo[i].r_f = (i + 1) % c->num_of_philo;
	}
	i = -1;
	c->start = get_ms();
	while (++i < c->num_of_philo)
	{
		usleep(50);
		philo[i].cur_time = get_ms();
		if (pthread_create(&philo[i].thr, NULL, cycle, (void *)(&philo[i]))
			|| pthread_detach(philo[i].thr))
			return (error_exit("run_philo error.", c, &philo));
	}
	die_checker(c, philo);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_cond	c;
	t_philo	*philo;

	if (!set_proc(argc, &argv[0], &c, &philo))
		return (1);
	if (!run_philo(&c, philo))
		return (1);
	free_arg(&c, &philo);
	return (0);
}
