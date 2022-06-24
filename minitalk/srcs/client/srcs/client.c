/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:47:43 by myunkim           #+#    #+#             */
/*   Updated: 2022/03/07 16:40:48 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../../libft/libft.h"

void	print_pid(int pid, size_t flag)
{
	char	*temp;

	temp = ft_itoa(pid);
	if (!temp)
		exit(1);
	if (flag)
		write(1, "server pid : ", 13);
	else
		write(1, "client pid : ", 13);
	write(1, temp, ft_strlen(temp));
	write(1, "\n", 1);
	free(temp);
}

void	server_sig_handler(int sig, siginfo_t *sig_info, void *ucontext)
{
	(void)sig_info;
	(void)ucontext;
	if (sig == SIGUSR1)
	{
		write(1, "Message send success.", 21);
		write(1, "\n", 1);
		exit(0);
	}
	else
	{
		write(1, "Cummunication failed.", 21);
		write(1, "\n", 1);
		exit(1);
	}
}

void	send_msg_len(int server, int msg_len)
{
	int	bc;
	int	bit_mask;

	bc = 0;
	bit_mask = 1 << (sizeof(int) * 8 - 1);
	while (bc < 32)
	{
		if (msg_len & bit_mask)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		if (bc != 31)
			msg_len = msg_len << 1;
		bc++;
		usleep(125);
	}
}

void	send_msg(int server, char *msg)
{
	int	i;
	int	bit_mask;

	bit_mask = 1 << (sizeof(char) * 8 - 1);
	while (*msg)
	{
		i = 0;
		while (i < 8)
		{
			if (*msg << i & bit_mask)
				kill(server, SIGUSR1);
			else
				kill(server, SIGUSR2);
			i++;
			usleep(125);
		}
		msg++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	client;
	int					server;

	if (--argc < 1)
		return (0);
	client.sa_sigaction = server_sig_handler;
	client.sa_flags = SA_SIGINFO;
	sigemptyset(&client.sa_mask);
	sigaction(SIGUSR1, &client, NULL);
	sigaction(SIGUSR2, &client, NULL);
	print_pid(getpid(), 0);
	server = ft_atoi(argv[1]);
	send_msg_len(server, (int)ft_strlen(argv[2]));
	send_msg(server, argv[2]);
	while (1)
		pause();
}
