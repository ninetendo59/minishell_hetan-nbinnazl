/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 03:08:48 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 03:40:58 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig	g_sig;

void	shell_init(t_meta *minishell)
{
	minishell->in = dup(0);
	minishell->out = dup(1);
	minishell->exit = 0;
	minishell->ret = 0;
	minishell->no_exec = 0;
	minishell->start = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_meta		minishell;

	(void)argc;
	(void)argv;
	shell_init(&minishell);
	ft_reset_fds(&minishell);
	ft_init_env(&minishell, env);
	ft_init_secret_env(&minishell, env);
	ft_lvl_increment(minishell.env);
	while (minishell.exit == 0)
	{
		ft_init_signal();
		ft_parse_input(&minishell);
		if (minishell.start != NULL
			&& ft_check_line(&minishell, minishell.start))
			ft_minishell(&minishell);
		ft_free_token(minishell.start);
	}
	ft_free_env(minishell.env);
	ft_free_env(minishell.secret_env);
	clear_history();
	exit(minishell.ret);
}
