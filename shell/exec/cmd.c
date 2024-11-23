#include "minishell.h"

static void	ft_cleanup(t_meta *minishell, char **cmd)
{
	ft_free_tab(cmd);
	ft_close(minishell->pipein);
	ft_close(minishell->pipeout);
	minishell->pipein = -1;
	minishell->pipeout = -1;
	minishell->charge = 0;
}

char	**ft_cmd_tab(t_token *start)
{
	t_token	*token;
	char	**tab;
	int		count;

	count = 2;
	token = start->next;
	while (token && token->type < TRUNC)
	{
		count++;
		token = token->next;
	}
	tab = malloc(sizeof(char *) * count);
	if (!tab)
		return (NULL);
	token = start->next;
	tab[0] = start->str;
	count = 1;
	while (token && token->type < TRUNC)
	{
		tab[count++] = token->str;
		token = token->next;
	}
	tab[count] = NULL;
	return (tab);
}

void	ft_exec_cmd(t_meta *minishell, t_token *token)
{
	char	**cmd;
	int		i;

	i = 0;
	if (minishell->charge == 0)
		return ;
	cmd = ft_cmd_tab(token);
	while (cmd && cmd[i])
	{
		cmd[i] = ft_expansions(cmd[i], minishell->env, minishell->ret);
		i++;
	}
	if (cmd)
	{
		if (ft_strcmp(cmd[0], "exit") == 0 && !ft_has_pipe(token))
			ft_b_exit(minishell, cmd);
		else if (ft_isbuiltin(cmd[0]))
			minishell->ret = ft_exec_builtin(cmd, minishell);
		else
			minishell->ret = ft_exec_bin(cmd, minishell->env, minishell);
	}
	ft_cleanup(minishell, cmd);
}
