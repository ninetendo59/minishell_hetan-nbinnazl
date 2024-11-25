#include "minishell.h"

void	ft_redir_and_exec(t_meta *minishell, t_token *token)
{
	t_token	*prev;
	t_token	*next;
	int		pipe;

	prev = ft_sep(token, 0, 0);
	next = ft_sep(token, 0, 1);
	pipe = 0;
	if (ft_istype(prev, TRUNC))
		redir(minishell, token, TRUNC);
	else if (ft_istype(prev, APPEND))
		redir(minishell, token, APPEND);
	else if (ft_istype(prev, INPUT))
		input(minishell, token);
	else if (ft_istype(prev, PIPE))
		pipe = minipipe(minishell);
	if (next && ft_istype(next, END) == 0 && pipe != 1)
		ft_redir_and_exec(minishell, next->next);
	if ((ft_istype(prev, END) || ft_istype(prev, PIPE) || !prev)
		&& pipe != 1 && minishell->no_exec == 0)
		ft_exec_cmd(minishell, token);
}

void	ft_minishell(t_meta *minishell)
{
	t_token	*token;
	int		status;

	token = ft_next_run(minishell->start, 0);
	if (ft_istypes(minishell->start, "TAI"))
		token = minishell->start->next;
	while (minishell->exit == 0 && token)
	{
		minishell->charge = 1;
		minishell->parent = 1;
		minishell->last = 1;
		ft_redir_and_exec(minishell, token);
		ft_reset_std(minishell);
		ft_close_fds(minishell);
		ft_reset_fds(minishell);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (minishell->last == 0)
			minishell->ret = status;
		if (minishell->parent == 0)
		{
			ft_free_token(minishell->start);
			exit(minishell->ret);
		}
		minishell->no_exec = 0;
		token = ft_next_run(token, 1);
	}
}
