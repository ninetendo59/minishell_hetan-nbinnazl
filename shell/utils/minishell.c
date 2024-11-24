#include "minishell.h"

void	ft_redir(t_meta *minishell, t_token *token, t_token *prev, int *pipe)
{
	if (ft_istype(prev, TRUNC))
		redir(minishell, token, TRUNC);
	else if (ft_istype(prev, APPEND))
		redir(minishell, token, APPEND);
	else if (ft_istype(prev, INPUT))
		input(minishell, token);
	else if (ft_istype(prev, PIPE))
		*pipe = minipipe(minishell);
}

void	ft_redir_and_exec(t_meta *minishell, t_token *token)
{
	t_token	*prev;
	t_token	*next;
	int		pipe;

	prev = ft_sep(token, 0, 0);
	next = ft_sep(token, 0, 1);
	pipe = 0;
	ft_redir(minishell, token, prev, &pipe);
	if (next && !ft_istype(next, END) && pipe != 1)
		ft_redir_and_exec(minishell, next->next);
	if ((ft_istype(prev, END) || ft_istype(prev, PIPE) || !prev) && pipe != 1 && !minishell->no_exec)
		ft_exec_cmd(minishell, token);
}


static void	ft_execute_and_reset(t_meta *minishell, t_token *token)
{
	int	status;

	minishell->charge = 1;
	minishell->parent = 1;
	minishell->last = 1;

	ft_redir_and_exec(minishell, token);
	ft_reset_std(minishell);
	ft_close_fds(minishell);
	ft_reset_fds(minishell);

	waitpid(-1, &status, 0);
	if (!minishell->last)
		minishell->ret = WEXITSTATUS(status);
	if (!minishell->parent)
	{
		ft_free_token(minishell->start);
		exit(minishell->ret);
	}
}

void	ft_minishell(t_meta *minishell)
{
	t_token	*token;

	token = ft_next_run(minishell->start, 0);
	printf("mshell start: %d, token: %d", !(!minishell->start), !(!token));
	if (ft_istypes(minishell->start, "TAI"))
	{
		printf("run1\n");
		token = minishell->start->next;
		printf("run2\n");
	}
	while (minishell->exit && token)
	{
		ft_execute_and_reset(minishell, token);
		minishell->no_exec = 0;
		token = ft_next_run(token, 1);
	}
	printf("run3\n");
}
