#include "minishell.h"

void	ft_handle_open_error(t_meta *minishell, char *file)
{
	ft_putstr_fd("MINISHELL: ", 2);
	ft_putstr_fd(file, 0);
	ft_putendl_fd(": No such file or directory", 2);
	minishell->ret = 1;
	minishell->no_exec = 1;
}

int	ft_open_file(const char *path, int flags, int perms)
{
	return (open(path, flags, perms));
}
