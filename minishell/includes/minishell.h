/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:19:48 by hyno              #+#    #+#             */
/*   Updated: 2022/06/22 15:05:26 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "../libft/libft.h"

enum e_tokentype {
	PIPE = 0,
	OUTPUT,
	APPEND,
	INPUT,
	HERE,
	STRING,
	CMD
};

typedef struct s_minimum
{
	enum e_tokentype	minitype;
	char				*ministr;
}			t_minimum;

typedef struct s_token
{
	enum e_tokentype	tokentype;
	char				**str2;
}			t_token;

typedef struct s_envval
{
	int		fd[2];
	char	*key;
	char	*value;
}			t_envval;

typedef enum e_exit
{
	VALID = 0,
	GENERAL = 1,
	BUILTIN = 1,
	NOTEXEC = 126,
	NOTFOUND = 127,
	OUTRANGE = 255
}			t_exit;

typedef struct s_fds
{
	int		cmd_in_fd;
	int		cmd_out_fd;
	int		next_cmd_fd;
	t_list	*rdr_fd;
	t_list	*rdr_pid;
}			t_fds;

//############################     parse     ################################
// parcing.c
int			parsing(t_list **token, char *str, t_list **envval);

// get_minimum_node.c
int			get_minimum(t_list **mini, char *str, t_list **envval);

// envval.c
int			set_envval_use_str(t_list **envval,	char *str);
void		set_envval(t_list **envval, char *key, char *value);
void		set_default_envval(t_list **envval, char **envp);
t_list		*search_envval(char *str, t_list *envval);

// replace_string.c
int			*replace_envval(char **str_ori, t_list *envval);

// token.c
int			get_token(t_list **token, t_list **mini, t_list **envval);

// parse_error.c
int			get_token_redi_error(int minitype, t_list **envval);

//############################    builtin    ################################
// unset.c
int			builtin_unset(char **args, t_list **envval);

// export.c
int			builtin_export(char **args, t_list **envval);

// env.c
int			builtin_env(t_list **envval);

// pwd.c
int			builtin_pwd(void);

// cd.c
int			builtin_cd(char **args, t_list **env);

// echo.c
int			builtin_echo(char **args);

// exit.c
int			builtin_exit(char **args, int pipe_flag);

//############################    utils    ################################
// util_string.c
char		*addstr(char *str1, char *str2);
char		*addchar(char *str, char word);

// util_lst.c
t_list		*ft_lst_addsort(t_list *src, t_list *newone,
				char *(*get_str)(t_list *));
void		ft_lstremove(t_list **lst, t_list *target, void (*del)(void *));
void		ft_lstadd_int(t_list **lst, int *i);
pid_t		*new_pidone(pid_t arg);
int			*new_intone(int arg);

// util_cast.c
t_token		*cont_tkn(t_list *list);
t_envval	*cont_env(t_list *list);
t_minimum	*cont_mini(t_list *list);
pid_t		*cont_pid(t_list *list);
char		*get_envstr(t_list *envone);

// free_struct.c
void		free_mini(void *ip);
void		free_token(void *ip);
void		free_envval(void *ip);
void		free_fd(void *ip);
void		free_pid(void *ip);

// utils.c
int			ft_calloc(void **ptr, size_t m_size, size_t n);
int			ft_isspace(char c);
void		ft_close(int fd);

//############################    exec    ################################
// command_path.c
char		*get_envval(t_list *env, char *comp);
char		*find_cmd(char *cmd, t_list *env);

// command.c
int			exec_builtin(char **args, t_list *env, int pipe_flag);
void		exec_extern(char *cmd, char **args, t_list *env);

// pipe.c
void		exec_pipe(t_fds *fdinfo);
int			is_nextpipe_left(t_list *head);

// redirection.c
int			exec_redir(t_list *token, t_fds *fdinfo, t_list **envval);

// redirection_exec.c
int			exec_redir_input(char *file);
int			exec_redir_output(char *file);
int			exec_redir_append(char *file);
int			exec_redir_heredoc(char *eof);

//############################   runtime   ###############################
// execute.c
void		execute(t_list **token, t_list **env);

// execute_cmd.c
pid_t		request_cmd_to_son(t_list **token, t_list *head,
				t_list **env, t_fds *fdinfo);

// execute_exit.c
void		exit_proc(char *entry, int exit_flag);

// execute_waitpid.c
void		exec_waitpid(t_list *rm_pid, t_list **env);

// termios.c
void		echoctl_on(void);
void		echoctl_off(void);

// signal.c
void		sigint_handler(int sig);
void		set_signal(void (*handler1)(int), void (*handler2)(int));

// error.c
int			ft_error(char *message, int error_flag,
				t_list **envval, int exitcode);
void		ft_error_exit(char *message);
void		*ft_malloc_guard(void *arg);

#endif
