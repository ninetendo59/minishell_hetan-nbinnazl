/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:24:06 by hetan             #+#    #+#             */
/*   Updated: 2024/10/15 00:09:37 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir(t_meta *minishell, t_token *token, int type)
{
	int	flags;

	ft_close(minishell->fdout);
	if (type == TRUNC)
		flags = (O_CREAT | O_WRONLY | O_TRUNC);
	else
		flags = (O_CREAT | O_WRONLY | O_APPEND);
	minishell->fdout = ft_open_file(token->str, flags, S_IRWXU);
	if (minishell->fdout == -1)
	{
		ft_handle_open_error(minishell, token->str);
		return ;
	}
	dup2(minishell->fdout, 1);
}

void	input(t_meta *minishell, t_token *token)
{
	ft_close(minishell->fdin);
	minishell->fdin = ft_open_file(token->str, O_RDONLY, S_IRWXU);
	if (minishell->fdin == -1)
	{
		ft_handle_open_error(minishell, token->str);
		return ;
	}
	dup2(minishell->fdin, 0);
}

int	minipipe(t_meta *minishell)
{
	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		ft_close(pipefd[1]);
		dup2(pipefd[0], 0);
		minishell->pipein = pipefd[0];
		minishell->pid = -1;
		minishell->parent = 0;
		minishell->no_exec = 0;
		return (2);
	}
	ft_close(pipefd[0]);
	dup2(pipefd[1], 1);
	minishell->pipeout = pipefd[1];
	minishell->pid = pid;
	minishell->last = 0;
	return (1);
}
