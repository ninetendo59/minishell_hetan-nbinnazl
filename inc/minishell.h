/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:52:11 by hetan             #+#    #+#             */
/*   Updated: 2024/11/28 11:45:25 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */
/*     Include libraries.                                                     */
/* ************************************************************************** */

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
// # if defined(__APPLE__) && defined (__MACH__)
// #  include <sys/syslimits.h>
// # elif defined(__linux__)
// #  include <linux/limits.h>
// #  define IS_LINUX 1
// # endif

/* ************************************************************************** */
/*     Constant declaration.                                                  */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

/* ************************************************************************** */
/*     Unclassified declaration.                                              */
/* ************************************************************************** */

// # ifndef EHCO || CD || PWD || EXP || UNS || ENV
// #  define ECHO "echo"
// #  define CD "cd"
// #  define PWD "pwd"
// #  define EXP "export"
// #  define UNS "unset"
// #  define ENV "env"
// # endif

typedef struct s_command
{
	const char		*name;
	void			(*func)(void);
}	t_command;

typedef struct s_exp
{
	char			*new_arg;
	int				i;
	int				j;
}	t_exp;

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_meta
{
	char			*cmd;
	char			*dir;
	t_env			*env;
	t_env			*secret_env;
	ssize_t			len;
	t_token			*start;
	int				ret;
	int				exit;
	// int		pipe;
	int				pipein;
	int				pipeout;
	int				pid;
	int				charge;
	int				left;
	int				d_left;
	int				right;
	int				d_right;
	int				fdin;
	int				fdout;
	int				in;
	int				out;
	int				parent;
	int				last;
	int				no_exec;
	// char			**history;
	// struct termios	orig_termios;
	// unsigned int	c_hist;
}	t_meta;

typedef struct s_cwd
{
	char	*cwd;
	char	*home;
	char	*disp;
}	t_cwd;

typedef struct s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_stat;
	pid_t			pid;
}	t_sig;

/* ************************************************************************** */
/*     UTILS                                                                  */
/* ************************************************************************** */

/* ************************************************************************** */
/*     expansion                                                              */
/* ************************************************************************** */

int		ft_arg_alloclen(const char *arg, t_env *env, int ret);

char	*ft_get_varvalue(const char *arg, int pos, t_env *env, int ret);

/* ************************************************************************** */
/*     fd                                                                     */
/* ************************************************************************** */

void	ft_close(int fd);
void	ft_reset_std(t_meta *minishell);
void	ft_close_fds(t_meta *minishell);
void	ft_reset_fds(t_meta *minishell);

/* ************************************************************************** */
/*     free                                                                   */
/* ************************************************************************** */

void	*ft_memdel(void *ptr);
void	ft_free_token(t_token *start);
void	ft_free_tab(char **tab);
void	ft_free_env(t_env *env);

/* ************************************************************************** */
/*     gnl                                                                    */
/* ************************************************************************** */

// int		ft_newline_check(char *stock, int read_size);

// char	*ft_buff_join(char *stock, char *buff);
// char	*ft_trim(char *stock);
// char	*ft_get_line(char *stock);

// char	*sh_free_storage(char **storage);
// char	*sh_store_data(char *storage);
// char	*sh_get_line(char *storage);
// char	*sh_get_fd(char *storage, int fd, int *ret);

/* ************************************************************************** */
/*     minishell                                                              */
/* ************************************************************************** */

void	ft_minishell(t_meta *minishell);

/* ************************************************************************** */
/*     parse                                                                  */
/* ************************************************************************** */

int		ft_issep(char *line, int i);
int		ft_ignore_sep(char *line, int i);
int		ft_quotes(char *line, int index);
int		ft_islast_validarg(t_token *token);
int		ft_check_line(t_meta *minishell, t_token *token);

/* ************************************************************************** */
/*     redir                                                                  */
/* ************************************************************************** */

void	ft_handle_open_error(t_meta *minishell, char *file);

int		ft_open_file(const char *path, int flags, int perms);

/* ************************************************************************** */
/*     token                                                                  */
/* ************************************************************************** */

t_token	*ft_sep(t_token *token, int skip, int next);
t_token	*ft_next_run(t_token *token, int skip);

/* ************************************************************************** */
/*     type                                                                   */
/* ************************************************************************** */

int		ft_istype(t_token *token, int type);
int		ft_istypes(t_token *token, char *types);
int		ft_has_pipe(t_token *token);

/* ************************************************************************** */
/*     utils                                                                  */
/* ************************************************************************** */

void	ft_skip_whitespace(const char *str, int *i);

int		ft_syntax_error(t_meta *minishell, char *token_str);
// int		ft_get_next_line(int fd, char **line);

/* ************************************************************************** */
/*     EXECUTE                                                                */
/* ************************************************************************** */

/* ************************************************************************** */
/*     bin                                                                    */
/* ************************************************************************** */

int		ft_mgc_box(char *path, char **args, t_env *env, t_meta *mini);
int		ft_exec_bin(char **args, t_env *env, t_meta *mini);

char	*ft_check_dir(char *bin, char *command);

/* ************************************************************************** */
/*     builtin                                                                */
/* ************************************************************************** */

int		ft_isbuiltin(char *command);
int		ft_exec_builtin(char **args, t_meta *minishell);

/* ************************************************************************** */
/*     cmd                                                                    */
/* ************************************************************************** */

void	ft_exec_cmd(t_meta *minishell, t_token *token);

char	**ft_cmd_tab(t_token *start);

/* ************************************************************************** */
/*     PARSE                                                                  */
/* ************************************************************************** */

/* ************************************************************************** */
/*     expansion                                                              */
/* ************************************************************************** */

char	*ft_expansions(char *arg, t_env *env, int ret);

/* ************************************************************************** */
/*     line                                                                   */
/* ************************************************************************** */

void	ft_parse_input(t_meta *minishell);

/* ************************************************************************** */
/*     token                                                                  */
/* ************************************************************************** */

void	ft_type_arg(t_token *token, int separator);
void	ft_squish_args(t_meta *minishell);

t_token	*ft_get_tokens(char *line);

/* ************************************************************************** */
/*     BUILTINS                                                               */
/* ************************************************************************** */

/* ************************************************************************** */
/*     echo                                                                   */
/* ************************************************************************** */

int		ft_b_echo(char **args);

/* ************************************************************************** */
/*     cd                                                                     */
/* ************************************************************************** */

int		ft_b_cd(char **args, t_env *env);

/* ************************************************************************** */
/*     pwd                                                                    */
/* ************************************************************************** */

int		ft_b_pwd(void);

/* ************************************************************************** */
/*     export                                                                 */
/* ************************************************************************** */

char	*ft_get_envname(char *dest, const char *src);

int		ft_envadd(const char *value, t_env *env);
int		ft_is_inenv(t_env *env, char *args);
int		ft_b_export(char **args, t_env *env, t_env *secret);

/* ************************************************************************** */
/*     unset                                                                  */
/* ************************************************************************** */

int		ft_b_unset(char **args, t_meta *minishell);

/* ************************************************************************** */
/*     env                                                                    */
/* ************************************************************************** */

int		ft_b_env(t_env *env);

/* ************************************************************************** */
/*     exit                                                                   */
/* ************************************************************************** */

void	ft_b_exit(t_meta *minishell, char **cmd);

/* ************************************************************************** */
/*     ENV                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*     env                                                                    */
/* ************************************************************************** */

int		ft_init_env(t_meta *minishell, char **env_array);
int		ft_init_secret_env(t_meta *minishell, char **env_array);

char	*ft_envto_str(t_env *lst);

size_t	ft_size_env(t_env *lst);

/* ************************************************************************** */
/*     get                                                                    */
/* ************************************************************************** */

int		ft_isenv_char(int c);
int		ft_isvalid_env(const char *env);
int		ft_envvalue_len(const char *env);

char	*ft_envvalue(char *env);
char	*ft_getenv_value(char *arg, t_env *env);

/* ************************************************************************** */
/*     shlvl                                                                  */
/* ************************************************************************** */

void	ft_lvl_increment(t_env *env);

/* ************************************************************************** */
/*     sort                                                                   */
/* ************************************************************************** */

int		ft_str_envlen(char **env);

void	ft_sort_env(char **tab, int env_len);
void	ft_print_sortedenv(t_env *env);

/* ************************************************************************** */
/*     SIGNAL                                                                 */
/* ************************************************************************** */

void	ft_sig_int(int code);
void	ft_sig_quit(int code);
void	ft_init_signal(void);

/* ************************************************************************** */
/*     REDIR                                                                  */
/* ************************************************************************** */

void	redir(t_meta *minishell, t_token *token, int type);
void	input(t_meta *minishell, t_token *token);

int		minipipe(t_meta *minishell);

/* ************************************************************************** */
/*     EXTENDS                                                                */
/* ************************************************************************** */

extern t_sig	g_sig;

#endif
