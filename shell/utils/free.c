#include "minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			ft_memdel(tab[i]);
		i++;
	}
	if (tab)
		ft_memdel(tab);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env && env->next)
	{
		tmp = env;
		env = env->next;
		ft_memdel(tmp->value);
		ft_memdel(tmp);
	}
	ft_memdel(env->value);
	ft_memdel(env);
}
