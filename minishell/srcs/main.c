/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:14 by hyno              #+#    #+#             */
/*   Updated: 2022/06/22 17:15:44 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"

static void	ascii_art(void)
{
	ft_putstr_fd("███╗   ███╗██╗███╗   ██╗██╗    \
		██╗  ██╗███████╗██╗     ██╗     \n", 1);
	ft_putstr_fd("████╗ ████║██║████╗  ██║██║    \
		██║  ██║██╔════╝██║     ██║     \n", 1);
	ft_putstr_fd("██╔████╔██║██║██╔██╗ ██║██║    \
		███████║█████╗  ██║     ██║     \n", 1);
	ft_putstr_fd("██║╚██╔╝██║██║██║╚██╗██║██║    \
		██╔══██║██╔══╝  ██║     ██║     \n", 1);
	ft_putstr_fd("██║ ╚═╝ ██║██║██║ ╚████║██║    \
		██║  ██║███████╗███████╗███████╗\n", 1);
	ft_putstr_fd("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    \
		╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n", 1);
	ft_putstr_fd("\n                             \
		         made hyno, myunkim       \n\n", 1);
}

static int	check_input(char *input)
{
	if (!ft_strlen(input))
		return (1);
	while (*input)
	{
		if (!ft_isspace(*input))
			return (0);
		input++;
	}
	return (1);
}

static int	loop(t_list **envval)
{
	char	*str;
	t_list	*token;

	str = 0;
	token = 0;
	while (1)
	{
		ft_lstclear(&token, free_token);
		free(str);
		str = readline("mini_hell>");
		if (str == NULL)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit(VALID);
		}
		if (check_input(str))
			continue ;
		add_history(str);
		if (parsing(&token, str, envval))
			continue ;
		execute(&token, envval);
	}
}

static void	shlvl_update(t_list **envval)
{
	char	*shlvl_str;

	shlvl_str = ft_malloc_guard(ft_itoa(\
		ft_atoi(cont_env(search_envval("SHLVL", *envval))->value) + 1));
	set_envval(envval, "SHLVL", shlvl_str);
	free(shlvl_str);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*envval;

	(void)argc;
	(void)argv;
	ascii_art();
	envval = 0;
	set_signal(sigint_handler, SIG_IGN);
	echoctl_off();
	set_default_envval(&envval, envp);
	shlvl_update(&envval);
	loop(&envval);
}
