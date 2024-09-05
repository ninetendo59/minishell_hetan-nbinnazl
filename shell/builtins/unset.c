#include "minishell.h"

static size_t	ft_env_size(char *env)
{
	size_t		i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

static void		ft_free_node(t_meta *minishell, t_env *env)
{
	if (minishell->env == env && env->next == NULL)
	{
		ft_memdel(minishell->env->value);
		minishell->env->value = NULL;
		minishell->env->next = NULL;
		return ;
	}
	ft_memdel(env->value);
	ft_memdel(env);
}

int				ft_unset(char **a, t_meta *minishell)
{
	t_env	*env;
	t_env	*tmp;

	env = minishell->env;
	if (!(a[1]))
		return (0);
	if (ft_strncmp(a[1], env->value, ft_env_size(env->value)) == 0)
	{
		minishell->env = (env->next) ? env->next : minishell->env;
		ft_free_node(minishell, env);
		return (0);
	}
	while (env && env->next)
	{
		if (ft_strncmp(a[1], env->next->value, ft_env_size(env->next->value)) == 0)
		{
			tmp = env->next->next;
			ft_free_node(minishell, env->next);
			env->next = tmp;
			return (0);
		}
		env = env->next;
	}
	return (0);
}