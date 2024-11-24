/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:30:52 by hetan             #+#    #+#             */
/*   Updated: 2024/11/25 03:49:49 by hetan            ###   ########.fr       */
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
	dat->cmd = malloc(sizeof(*dat->cmd) * (BUFFER_SIZE + 1));
	dat->dir = malloc(sizeof(*dat->dir) + 1);
	dat->len = 0;
	dat->ret = 0;
	dat->exit = 0;
	dat->d_left = 0;
	dat->d_right = 0;
	dat->left = 0;
	dat->right = 0;
	dat->exit = 0;
	dat->ret = 0;
	dat->no_exec = 0;
	dat->in = dup(0);
	dat->out = dup(1);
	dat->env = NULL;
	dat->secret_env = NULL;
	// dat->pipe = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_meta	dat;
	static char	*last_cmd;
	(void)argc;
	(void)argv;

	// ft_init_signal();
	ft_init_list(&dat);
	ft_reset_fds(&dat);
	ft_init_env(&dat, env);
	ft_init_secret_env(&dat, env);
	ft_lvl_increment(dat.env);
	last_cmd = NULL;
	if (!dat.cmd || !dat.dir)
		exit(1);
	// curr_dir();
	while (dat.exit == 0)
	{
		curr_dir();
		dat.cmd = readline("");

		printf("done 1\n");
		ft_init_signal();
		printf("done 2\n");
		ft_parse_input(&dat);
		printf("done 3\n");
		if (dat.start != NULL && ft_check_line(&dat, dat.start))
		{
			printf("done test\n");
			ft_minishell(&dat);
		}
		printf("done 4\n");
		ft_free_token(dat.start);
		printf("done 5\n");
		
		if (!dat.cmd || !strcmp(dat.cmd, "exit"))
			exit(0);
		printf("done 6\n");
		if ((!last_cmd || ft_strcmp(last_cmd, dat.cmd) != 0) && IS_LINUX)
		{
			add_history(dat.cmd);
			free(last_cmd);
			last_cmd = ft_strdup(dat.cmd);
		}
		else if (!IS_LINUX)
			add_history(dat.cmd);
		printf("done 7\n");
		*dat.cmd = '\0';
		printf("done 8\n");
	}
	ft_free_env(dat.env);
	ft_free_env(dat.secret_env);
	free(last_cmd);
	exit(dat.ret);
}
