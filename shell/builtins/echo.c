#include "minishell.h"

int	ft_b_echo(char **args)
{
	int	i;
	int	n_opt;

	i = 1;
	n_opt = 0;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		n_opt = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!n_opt)
		write(1, "\n", 1);
	return (0);
}
