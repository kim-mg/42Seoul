/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:49:21 by myunkim           #+#    #+#             */
/*   Updated: 2022/03/07 16:40:56 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"

void	init_info(t_info *info)
{
	info->pid = 0;
	info->msg = 0;
	info->len = 0;
	info->len_bc = 1;
	info->msg_idx = 0;
	info->c = 0;
	info->c_bc = 1;
}

void	get_msg_len(int sig, t_info *info)
{
	if (sig == SIGUSR1)
		info->len += 1;
	if (info->len_bc != 32)
		info->len = info->len << 1;
	else
	{
		info->msg = malloc(sizeof(char) * (info->len + 1));
		if (!info->msg)
			exit(1);
	}
	info->len_bc += 1;
}

void	recieve_msg(int sig, t_info *info)
{
	if (sig == SIGUSR1)
		info->c += 1;
	if (info->c_bc != 8)
	{
		info->c = info->c << 1;
		info->c_bc += 1;
	}
	else
	{
		info->msg[info->msg_idx++] = info->c;
		info->c = 0;
		info->c_bc = 1;
		if (info->msg_idx == info->len)
			info->msg[info->msg_idx] = 0;
	}
}

void	print_msg(t_info *info)
{
	print_pid(info->pid, 0);
	write(1, info->msg, info->len);
	write(1, "\n", 1);
}

void	chat_proc(int sig, siginfo_t *sig_info, void *ucontext)
{
	static t_info	info;

	(void)ucontext;
	if (info.pid == 0)
	{
		init_info(&info);
		info.pid = sig_info->si_pid;
	}
	if (info.pid != sig_info->si_pid)
		kill(sig_info->si_pid, SIGUSR2);
	if (info.len_bc != 33)
		get_msg_len(sig, &info);
	else if (info.msg_idx != info.len)
		recieve_msg(sig, &info);
	if (info.len && info.msg_idx == info.len)
	{
		print_msg(&info);
		free(info.msg);
		kill(info.pid, SIGUSR1);
		init_info(&info);
	}
}
