/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:52:11 by hetan             #+#    #+#             */
/*   Updated: 2024/04/01 05:22:32 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
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
# include <readline/readline.h>
# include <readline/history.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef EHCO || CD || PWD || EXP || UNS || ENV
#  define ECHO "echo"
#  define CD "cd"
#  define PWD "pwd"
#  define EXP "export"
#  define UNS "unset"
#  define ENV "env"
# endif

typedef struct s_command
{
	const char *name;
	void (*func)(void);
}               t_command;

typedef struct s_meta
{
	char	*cmd;
	char	**hist;
	ssize_t	len;
}   t_meta;

typedef struct s_cwd
{
	char *cwd;
	char *home;
	char *disp;
}	t_cwd;

void curr_dir(void);

void ctrl_c(int sig);

void check_sig(void);


#endif