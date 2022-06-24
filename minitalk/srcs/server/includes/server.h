/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:49:35 by myunkim           #+#    #+#             */
/*   Updated: 2022/03/06 01:38:38 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"

typedef struct s_info
{
	int		pid;
	char	*msg;
	int		len;
	int		len_bc;
	int		msg_idx;
	int		c;
	int		c_bc;
}			t_info;

void	print_pid(int pid, size_t flag);

void	chat_proc(int sig, siginfo_t *sig_info, void *ucontext);

#endif
