#include "minishell.h"

static	int	ft_get_argslen(char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	ft_b_echo(char **args)
{
	int	i;
	int	n_opt;

	i = 1;
	n_opt = 0;
	if (ft_get_argslen(args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			n_opt = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_opt == 0)
		write(1, "\n", 1);
	return (0);
}

// int	main(int i, char **c)
// {
// 	int	result = 0;

// 	if (i > 1)
// 	{
// 		if (ft_strcmp(c[1], "echo") == 0)
//         {
//             c++;
// 			result = ft_b_echo(c);
//         }
// 	}
// 	return (result);
// }