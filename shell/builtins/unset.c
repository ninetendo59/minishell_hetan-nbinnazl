#include "minishell.h"

static size_t	ft_env_size(const char *env)
{
	size_t		i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

static void	ft_free_node(t_meta *minishell, t_env *env, t_env *prev)
{
	if (prev)
		prev->next = env->next;
	else
		minishell->env = env->next;
	ft_memdel(env->value);
	ft_memdel(env);
}

int	ft_b_unset(char **args, t_meta *minishell)
{
	t_env	*env;
	t_env	*tmp;

	env = minishell->env;
	tmp = NULL;
	if (!(args[1]))
		return (0);
	while (env)
	{
		if (ft_strncmp(args[1], env->value, ft_env_size(env->value)) == 0)
			return (ft_free_node(minishell, env, tmp), 0);
		tmp = env;
		env = env->next;
	}
	return (0);
}
