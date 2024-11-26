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

// static void	disp_home(char *cwd, char *home)
// {
// 	char	*display;

// 	display = malloc(strlen(cwd) - strlen(home) + 2);
// 	if (!display)
// 		return ;
// 	strcpy(display, "~");
// 	strcat(display, cwd + strlen(home));
// 	write(1, display, strlen(display));
// 	free(display);
// }

// static void	curr_dir(void)
// {
// 	char	*cwd;
// 	char	*home;

// 	cwd = malloc(sizeof(*cwd) * (BUFFER_SIZE + 1));
// 	if (!cwd)
// 		return ;
// 	write(1, "\e[32m⚪ MINISHELL: \e[0m", strlen("\e[32m⚪ MINISHELL: \e[0m"));
// 	if (getcwd(cwd, BUFFER_SIZE + 1) != NULL)
// 	{
// 		home = getenv("HOME");
// 		if (home != NULL && strncmp(cwd, home, strlen(home)) == 0)
// 			disp_home(cwd, home);
// 		else
// 			write(1, cwd, strlen(cwd));
// 	}
// 	else
// 		perror("getcwd() error");
// 	write(1, "$ >", 3);
// 	rl_redisplay();
// 	free(cwd);
// }

// void	ft_init_list(t_meta *dat)
// {
	// dat->cmd = malloc(sizeof(*dat->cmd) * (BUFFER_SIZE + 1));
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
	// dat->env = NULL;
	// dat->secret_env = NULL;
	// dat->pipe = 0;
// }

int	main(int argc, char **argv, char **env)
{
	static char	*last_cmd;
	t_meta		dat;

	(void)argc;
	(void)argv;
	// ft_init_signal();
	// ft_parse_input(&dat);
	// ft_init_list(&dat);
	dat.in = dup(0);
	dat.out = dup(1);
	dat.exit = 0;
	dat.ret = 0;
	dat.no_exec = 0;
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
		// curr_dir();
		// dat.cmd = readline("");

        // char buffer[3] = {0};
        // read(STDIN_FILENO, buffer, 3);

        // if (buffer[0] == '\033' && buffer[1] == '[') {
        //     switch (buffer[2]) {
        //         case 'A': read_history(dat.cmd); break;
        //         case 'B': printf("Down arrow pressed\n"); break;
        //         case 'C': printf("Right arrow pressed\n"); break;
        //         case 'D': printf("Left arrow pressed\n"); break;
        //     }
		// }
		ft_init_signal();
		ft_parse_input(&dat);
		if (dat.start != NULL && ft_check_line(&dat, dat.start))
			ft_minishell(&dat);
		ft_free_token(dat.start);

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
		// *dat.cmd = '\0';
	}
	ft_free_env(dat.env);
	ft_free_env(dat.secret_env);
	free(last_cmd);
	exit(dat.ret);
}
