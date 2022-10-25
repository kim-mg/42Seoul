#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

#define TYPE_PIPE	1
#define TYPE_DONE	2

typedef struct s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipe[2];
	struct t_list	*prev;
	struct t_list	*next;
}t_list;	

int	ft_strlen(char *s)
{
	char *t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

void	exit_fatal(char *err)
{
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	list_add(t_list **cmds, char *arg)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
	new->args = NULL;
	new->length = 0;
	new->type = 0;
	new->prev = NULL;
	new->next = NULL;
	while (*cmds)
		cmds++;
	
}

void	parse_arg(t_list **cmds, char *arg)
{
	int done;

	if (strcmp(";", arg) == 0)
		done = 1;
	else
		done = 0;

	if (done && !*cmds)
		return ;
	else if (!done && (!*cmds || (*cmds)->type > 0))
	{
		list_add(cmds, arg);
		return ;
	}
	else if (strcmp("|", arg) == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (done)
		(*cmds)->type = TYPE_DONE;
	else
		arg_add(*cmds, arg);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*cmds;
	int		ret;
	int		i;

	ret = 0;
	cmds = NULL;
	i = 0;
	while (i < argc)
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmd(&cmds, envp);
	lst_clear(&cmds);
	return (ret);
}
