#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_DONE	2

typedef struct s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipe[2];
	struct s_list	*prev;
	struct s_list	*next;
}t_list;

int	ft_strlen(char *s)
{
	char	*temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

int	print_error(char *err)
{
	write(STDERR_FILENO, err, ft_strlen(err));
	return (1);
}

int	error_fatal(void)
{
	print_error("error: fatal\n");
	exit(1);
	return (1);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		error_fatal();
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	add_arg(t_list **cmds, char *arg)
{
	char	**new;
	int	i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * ((*cmds)->length + 2));
	if (!new)
		return (error_fatal());
	while (i < (*cmds)->length)
	{
		new[i] = (*cmds)->args[i];
		i++;
	}
	if ((*cmds)->args)
		free((*cmds)->args);
	(*cmds)->args = new;
	(*cmds)->args[i++] = ft_strdup(arg);
	(*cmds)->args[i] = NULL;
	(*cmds)->length++;
	return (0);
}

int	lst_add(t_list **cmds, char *arg)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (error_fatal());
	new->args = NULL;
	new->length = 0;
	new->type = TYPE_END;
	new->prev = NULL;
	new->next = NULL;
	if (*cmds)
	{
		(*cmds)->next = new;
		new->prev = *cmds;
	}
	*cmds = new;
	return (add_arg(cmds, arg));
}

int	parse_arg(t_list **cmds, char *arg)
{
	int	done;

	if (strcmp(";", arg) == 0)
		done = 1;
	else
		done = 0;

	if (done && (!(*cmds)))
		return (0);
	else if (!done && (!(*cmds) || ((*cmds)->type > TYPE_END)))
		return (lst_add(cmds, arg));
	else if (strcmp("|", arg) == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (done)
		(*cmds)->type = TYPE_DONE;
	else
		return (add_arg(cmds, arg));
	return (0);
}

int	lst_rewind(t_list **list)
{
	while (*list && (*list)->prev)
		*list = (*list)->prev;
	return (0);
}

int	lst_clear(t_list **list)
{
	t_list	*temp;
	int	i;

	lst_rewind(list);
	while (*list)
	{
		temp = (*list)->next;
		i = 0;
		while ((*list)->args[i])
			free((*list)->args[i++]);
		free((*list)->args);
		free((*list));
		*list = temp;
	}
	return (0);
}

int	exec_cmd(t_list *cmd, char **envp)
{
	pid_t	pid;
	int	on_pipe;
	int	rtn;
	int	status;

	rtn = 0;
	on_pipe = 0;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		on_pipe = 1;
		if (pipe(cmd->pipe))
			return (error_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (error_fatal());
	else if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE && dup2(cmd->pipe[1], STDOUT_FILENO) < 0)
			return (error_fatal());
		if (cmd->prev && cmd->prev->type == TYPE_PIPE
			&& dup2(cmd->prev->pipe[0], STDIN_FILENO) < 0)
			return (error_fatal());
		rtn = execve(cmd->args[0], cmd->args, envp);
		if (rtn < 0)
		{
			print_error("error: cannot execute ");
			print_error(cmd->args[0]);
			print_error("\n");
		}
		exit(rtn);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (on_pipe)
		{
			close(cmd->pipe[1]);
			if (!(cmd->next) || cmd->type == TYPE_DONE)
				close(cmd->pipe[0]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipe[0]);
		if (WIFEXITED(status))
			rtn = WEXITSTATUS(status);
	}
	return (rtn);
}

int	exec_cmds(t_list **cmds, char **envp)
{
	t_list	*cur;
	int	rtn;

	rtn = 0;
	lst_rewind(cmds);
	while (*cmds)
	{
		cur = *cmds;
		if (strcmp("cd", cur->args[0]) == 0)
		{
			rtn = 0;
			if (cur->length < 2)
				rtn = print_error("error: cd: bad arguments\n");
			else if (chdir(cur->args[1]))
			{
				rtn = print_error("error: cd: cannot change directory to ");
				print_error(cur->args[1]);
				print_error("\n");
			}
		}
		else
			rtn = exec_cmd(cur, envp);
		if (!(*cmds)->next)
			break ;
		*cmds = (*cmds)->next;
	}
	return (rtn);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*cmds;
	int	i;
	int	rtn;

	rtn = 0;
	i = 1;
	cmds = NULL;
	while (i < argc)
		parse_arg(&cmds, argv[i++]);

	// lst_rewind(&cmds);
	// int cnt = 0;
	// while (cmds)
	// {
	// 	int n = 0;
	// 	printf(">>> cmd[%d] <<<\n", cnt);
	// 	while (cmds->args[n])
	// 		printf("%s\n", cmds->args[n++]);
	// 	cmds = cmds->next;
	// 	cnt++;
	// }
	if (cmds)
		rtn = exec_cmds(&cmds, envp);
	lst_clear(&cmds);
	return (rtn);
}