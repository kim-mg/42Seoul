/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:26:42 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/17 19:32:34 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

void	echoctl_on(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag = term.c_lflag | ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	echoctl_off(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag = term.c_lflag & ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
