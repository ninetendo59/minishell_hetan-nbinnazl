#include "minishell.h"

int	ft_strisnum(const char *str)
{
	if (!str || (*str == '-' && !*(str + 1)))
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	ft_b_exit(t_meta *minishell, char **cmd)
{
	minishell->exit = 1;
	ft_putstr_fd("exit ", 2);
	if (cmd[1])
		ft_putendl_fd("with numeric argument", 2);
	else
		ft_putendl_fd("without numeric argument", 2);
	if (cmd[1] && cmd[2])
	{
		minishell->ret = 1;
		ft_putendl_fd("MINISHELL: exit: too many arguments", 2);
		return ;
	}
	if (cmd[1] && ft_strisnum(cmd[1]) == 0)
	{
		minishell->ret = 255;
		ft_putstr_fd("MINISHELL: exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(": numeric argument required\n", 2);
		return ;
	}
	if (cmd[1])
		minishell->ret = ft_atoi(cmd[1]);
	else
		minishell->ret = 0;
	ft_putendl_fd("MINISHELL: Successfully exited.", 2);
}
