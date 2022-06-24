/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:47:16 by myunkim           #+#    #+#             */
/*   Updated: 2022/03/06 01:38:40 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

int	main(void)
{
	struct sigaction	chat;

	print_pid(getpid(), 1);
	chat.sa_sigaction = chat_proc;
	chat.sa_flags = SA_SIGINFO;
	sigemptyset(&chat.sa_mask);
	sigaction(SIGUSR1, &chat, NULL);
	sigaction(SIGUSR2, &chat, NULL);
	while (1)
		pause();
}
