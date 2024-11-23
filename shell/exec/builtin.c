#include "minishell.h"

int	ft_isbuiltin(char *command)
{
	const char	*builtins[7] = {
		"echo",
		"cd",
		"pwd",
		"env",
		"export",
		"unset",
		NULL
	};
	int			i;

	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(command, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_exec_builtin(char **args, t_meta *minishell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_b_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_b_cd(args, minishell->env));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_b_pwd());
	if (ft_strcmp(args[0], "env") == 0)
		ft_b_env(minishell->env);
	else if (ft_strcmp(args[0], "export") == 0)
		ft_b_export(args, minishell->env, minishell->secret_env);
	else if (ft_strcmp(args[0], "unset") == 0)
		ft_b_unset(args, minishell);
	return (0);
}
