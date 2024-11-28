/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:30:52 by hetan             #+#    #+#             */
/*   Updated: 2024/11/28 12:08:45 by hetan            ###   ########.fr       */
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
// 	dat->cmd = ft_calloc((BUFFER_SIZE + 1), sizeof(*dat->cmd));
// 	if (!dat->cmd)
// 		return ;
// 	dat->dir = ft_calloc(1, sizeof(*dat->dir));
// 	if (!dat->dir)
// 		return ;
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

// void	enable_raw_mode(struct termios *orig_termios)
// {
// 	struct termios raw;

// 	tcgetattr(STDIN_FILENO, orig_termios);
// 	raw = *orig_termios;
// 	raw.c_lflag &= ~(ECHO | ICANON | ISIG);
// 	raw.c_iflag &= ~(IXON | ICRNL);
// 	raw.c_oflag &= ~(OPOST);
// 	raw.c_cflag |= (CS8);

// 	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
// }

// void disable_raw_mode(struct termios *orig_termios)
// {
//     // Restore the original terminal attributes
//     tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);
// }

int	main(int argc, char **argv, char **env)
{
	// static char	*last_cmd;
	t_meta		dat;

	(void)argc;
	(void)argv;
	// ft_init_signal();
	// ft_parse_input(&dat);
	// dat.history = malloc(sizeof(char));
	// if (!dat.history)
	// 	exit(EXIT_FAILURE);
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
	// last_cmd = NULL;
	
	// if (!dat.history)
	// 	EXIT_FAILURE;
	// dat.c_hist = 0;
	if (!dat.cmd || !dat.dir)
		exit(1);
	// curr_dir();
	// enable_raw_mode(&dat.orig_termios);
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

		// if (!dat.cmd || !strcmp(dat.cmd, "exit"))
		// 	exit(0);
		// if ((!last_cmd || ft_strcmp(last_cmd, dat.cmd) != 0) && IS_LINUX)
		// {
		// 	add_history(dat.cmd);
		// 	free(last_cmd);
		// 	last_cmd = ft_strdup(dat.cmd);
		// }
		// else if (!IS_LINUX)
		// 	add_history(dat.cmd);
		// // *dat.cmd = '\0';
		// if (dat.cmd)
		// 	read_history(dat.cmd);
		// *dat.cmd = '\0';
		// disable_raw_mode(&dat.orig_termios);
	}
	ft_free_env(dat.env);
	ft_free_env(dat.secret_env);
	// free(dat.cmd);
	// free(last_cmd);
	// free(dat.dir);
	// clear_history();
	exit(dat.ret);
}

// int main(int argc, char **argv, char **env)
// {
//     static char *last_cmd;
//     t_meta dat;

//     (void)argc;
//     (void)argv;
//     dat.in = dup(0);
//     dat.out = dup(1);
//     dat.exit = 0;
//     dat.ret = 0;
//     dat.no_exec = 0;
//     ft_reset_fds(&dat);
//     ft_init_env(&dat, env);
//     ft_init_secret_env(&dat, env);
//     ft_lvl_increment(dat.env);
//     last_cmd = NULL;
// 	if (!dat.cmd || !dat.dir)
// 		exit(1);
//     while (dat.exit == 0)
//     {
//         ft_init_signal();
//         dat.cmd = readline("\033[0;36m\033[1mMINISHELL: \033[0m");
//         if (!dat.cmd)
//         {
//             ft_putendl_fd("exit", 2);
//             break;
//         }
//         if (*dat.cmd)
//         {
//             if (!last_cmd || strcmp(last_cmd, dat.cmd) != 0)
//             {
//                 add_history(dat.cmd);
//                 free(last_cmd);
//                 last_cmd = strdup(dat.cmd);
//             }
//         }
//         ft_parse_input(&dat);
//         if (dat.cmd)
//         {
//             free(dat.cmd);
//             dat.cmd = NULL;
//         }
//     }

//     free(last_cmd);
//     ft_free_env(dat.env);
//     ft_free_env(dat.secret_env);
//     exit(dat.ret);
// }


// int	main(int argc, char **argv, char **env)
// {
//     static char		*last_cmd;
//     t_meta			dat;
//     struct termios	orig_termios;

//     (void)argc;
//     (void)argv;
//     dat.history = malloc(sizeof(char));
//     if (!dat.history)
//         exit(EXIT_FAILURE);
//     ft_init_list(&dat);
//     dat.in = dup(0);
//     dat.out = dup(1);
//     dat.exit = 0;
//     dat.ret = 0;
//     dat.no_exec = 0;
//     ft_reset_fds(&dat);
//     ft_init_env(&dat, env);
//     ft_init_secret_env(&dat, env);
//     ft_lvl_increment(dat.env);
//     last_cmd = NULL;
    
//     if (!dat.history)
//         exit(EXIT_FAILURE);
//     dat.c_hist = 0;
//     if (!dat.cmd || !dat.dir)
//         exit(1);

//     enable_raw_mode(&orig_termios);
//     while (dat.exit == 0)
//     {
//         ft_init_signal();
//         ft_parse_input(&dat);
//         if (dat.start != NULL && ft_check_line(&dat, dat.start))
//             ft_minishell(&dat);
//         ft_free_token(dat.start);
//         if (dat.cmd)
//             add_history(dat.cmd);
//         *dat.cmd = '\0';
//     }
//     disable_raw_mode(&orig_termios);
//     ft_free_env(dat.env);
//     ft_free_env(dat.secret_env);
//     free(dat.cmd);
//     free(last_cmd);
//     free(dat.dir);
//     clear_history();
//     exit(dat.ret);
// }