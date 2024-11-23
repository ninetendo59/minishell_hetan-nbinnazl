#include "minishell.h"

int	ft_b_env(t_env *env)
{
	while (env)
	{
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
	return (0);
}
