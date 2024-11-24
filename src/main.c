/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:30:52 by hetan             #+#    #+#             */
/*   Updated: 2024/11/24 18:04:12 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig	g_sig;

static void	disp_home(char *cwd, char *home)
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

static void	curr_dir(void)
{
	char	*cwd;
	char	*home;

	cwd = malloc(sizeof(*cwd) * (BUFFER_SIZE + 1));
	if (!cwd)
		return ;
	write(1, "\e[32m⚪ MINISHELL: \e[0m", strlen("\e[32m⚪ MINISHELL: \e[0m"));
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

void	ft_init_list(t_meta *dat)
{
	// dat->dir = malloc(sizeof(*dat->dir) + 1);
	// dat->len = 0;
	// dat->ret = 0;
	// dat->exit = 0;
	// dat->d_left = 0;
	// dat->d_right = 0;
	// dat->left = 0;
	// dat->right = 0;
	// dat->exit = 0;
	// dat->ret = 0;
	// dat->no_exec = 0;
	// dat->in = dup(0);
	// dat->out = dup(1);
	dat->cmd = malloc(BUFFER_SIZE + 1);
	if (!dat->cmd)
		return ;
	dat->secret_env = NULL;
	dat->len = 0;
	dat->start = NULL;
	dat->ret = 0;
	dat->exit = 0;
	dat->pipein = 0;
	dat->pipeout = 0;
	dat->pid = 0;
	dat->charge = 0;
	dat->left = 0;
	dat->d_left = 0;
	dat->right = 0;
	dat->d_right = 0;
	dat->fdin = 0;
	dat->fdout = 1;
	dat->in = dup(0);
	dat->out = dup(1);
	dat->parent = 0;
	dat->last = 0;
	dat->no_exec = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_meta	dat;
	static char	*last_cmd;
	(void)argc;
	(void)argv;

	// ft_init_signal();
	ft_init_list(&dat);
	// dat.cmd = malloc((BUFFER_SIZE + 1));
	ft_reset_fds(&dat);
	ft_init_env(&dat, env);
	ft_init_secret_env(&dat, env);
	ft_lvl_increment(dat.env);
	last_cmd = NULL;
	if (!dat.cmd)
		exit(1);
	while (dat.exit == 0)
	{
		curr_dir();
		dat.cmd = readline("");


		ft_init_signal();
		printf("done\n");
		ft_parse_input(&dat);
		printf("done\n");
		if (dat.start != NULL && ft_check_line(&dat, dat.start))
			ft_minishell(&dat);
		ft_free_token(dat.start);
		printf("done\n");
		
		if (!dat.cmd || !strcmp(dat.cmd, "exit"))
			exit(0);
		if ((!last_cmd || ft_strcmp(last_cmd, dat.cmd) != 0) && IS_LINUX)
		{
			add_history(dat.cmd);
			free(last_cmd);
			last_cmd = ft_strdup(dat.cmd);
		}
		else if (!IS_LINUX)
			add_history(dat.cmd);
		*dat.cmd = '\0';
	}
	ft_free_env(dat.env);
	ft_free_env(dat.secret_env);
	// free(dat.dir);
	free (dat.cmd);
	// rl_clear_history();
	free(last_cmd);
	exit(dat.ret);
}
