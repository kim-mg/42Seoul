/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:36:11 by myunkim           #+#    #+#             */
/*   Updated: 2022/05/20 03:41:00 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>

typedef enum e_stat
{
	DEAD,
	GRAB,
	EATING,
	SLEEPING,
	THINKING,
	FULL
}			t_stat;

typedef struct s_cond
{
	int				num_of_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				req_eat;
	int				full;
	int				done;
	long long		start;
	pthread_mutex_t	p;
	pthread_mutex_t	*f;
}			t_cond;

typedef struct s_philo
{
	t_cond		*c;
	pthread_t	thr;
	int			i;
	int			l_f;
	int			r_f;
	int			n_eat;
	long long	cur_time;
}			t_philo;

int			ft_strlen(char *s);
int			ft_atoi(const char *nptr);
void		ft_putnbr_fd(int n, int fd);

long long	get_ms(void);
void		elapse(long long start, long long comp_time);

void		free_arg(t_cond *c, t_philo **philo);
int			error_exit(char *s, t_cond *c, t_philo **philo);

int			print_line(t_philo *philo, t_stat stat);

void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

void		die_checker(t_cond *c, t_philo *philo);
#endif