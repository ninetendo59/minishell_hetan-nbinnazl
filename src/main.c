/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:30:52 by hetan             #+#    #+#             */
/*   Updated: 2024/09/08 06:12:20 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig	g_sig;

void	disp_home(char *cwd, char *home)
{
	char	*display;

	display = malloc(strlen(cwd) - strlen(home) + 2);
	if (!display)
		return ;
	strcpy(display, "~");
	strcat(display, cwd + strlen(home));
	write(1, display, strlen(display));
	free(display);
}

void	curr_dir(void)
{
	char	*cwd;
	char	*home;

	cwd = malloc(sizeof(*cwd) * (BUFFER_SIZE + 1));
	if (!cwd)
		return ;
	write(1, "\e[32mMINISHELL: \e[0m", strlen("\e[32mMINISHELL: \e[0m"));
	if (getcwd(cwd, BUFFER_SIZE + 1) != NULL)
	{
		home = getenv("HOME");
		if (home != NULL && strncmp(cwd, home, strlen(home)) == 0)
			disp_home(cwd, home);
		else
			write(1, cwd, strlen(cwd));
	}
	else
		perror("getcwd() error");
	write(1, "$ >", 3);
	rl_redisplay();
	free(cwd);
}



// void check_sig(void)
// {
// 	signal(SIGINT, ctrl_c);
// 	signal(SIGQUIT, SIG_IGN);
// 	return ;
// }

// void ctrl_c(int sig)
// {
// 	(void)sig;
// 	write(1, "\n", 1);
// 	current_dir();
// }

void	ini_list(t_meta *dat)
{
	dat->cmd = malloc(sizeof(*dat->cmd) * (BUFFER_SIZE + 1));
	dat->dir = malloc(sizeof(*dat->dir) + 1);
	dat->len = 0;
	dat->ret = 0;
	dat->exit = 0;
}

// void    shell_cmd (t_meta *dat)
// {
// 	if (strncmp(dat->cmd, "echo", ))
// }

int	main(int argc, char **argv, char **env)
{
	t_meta	dat;
	(void)argc;
	(void)argv;

	ft_init_signal();
	ini_list(&dat);
	ft_init_env(&dat, env);

	if (!dat.cmd || !dat.dir)
		exit(1);
	while (dat.exit == 0)
	{
		check_sig();
		curr_dir();
		dat.cmd = readline("");
		if (!dat.cmd || !strcmp(dat.cmd, "exit"))
		{
			// free_list(&dat);
			exit(0);
		}
		add_history(dat.cmd);
		// shell_cmd(&dat);
		*dat.cmd = '\0';
	}
	ft_free_env(dat.env);
	exit(dat.ret);
}
