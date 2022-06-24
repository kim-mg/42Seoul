/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:40:26 by myunkim           #+#    #+#             */
/*   Updated: 2022/05/20 03:41:54 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/philo.h"

void	free_arg(t_cond *c, t_philo **philo)
{
	int	i;

	i = -1;
	if (philo && *philo)
		while (++i < c->num_of_philo)
			pthread_join((*philo)[i].thr, NULL);
	i = -1;
	if (c->f)
		while (++i < c->num_of_philo)
			pthread_mutex_destroy(&c->f[i]);
	pthread_mutex_destroy(&c->p);
	if (philo && *philo)
		free(*philo);
	if (c->f)
		free(c->f);
}

int	error_exit(char *s, t_cond *c, t_philo **philo)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	free_arg(c, philo);
	write(2, "Error >> ", 9);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (0);
}
