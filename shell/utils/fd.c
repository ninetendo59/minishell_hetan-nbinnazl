#include "minishell.h"

void	ft_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	ft_reset_std(t_meta *minishell)
{
	dup2(minishell->in, 0);
	dup2(minishell->out, 1);
}

void	ft_close_fds(t_meta *minishell)
{
	ft_close(minishell->fdin);
	ft_close(minishell->fdout);
	ft_close(minishell->pipein);
	ft_close(minishell->pipeout);
}

void	ft_reset_fds(t_meta *minishell)
{
	minishell->fdin = -1;
	minishell->fdout = -1;
	minishell->pipein = -1;
	minishell->pipeout = -1;
	minishell->pid = -1;
}
