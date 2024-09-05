#include "minishell.h"

int ft_str_envlen(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void    ft_sort_env(char **tab, int env_len)
{
	int		sorted;
	int		i;
	char	*tmp;

	sorted = 0;
	while (tab && sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
		env_len--;
	}
}

void    ft_print_sortedenv(t_env *env)
{
	int     i;
	char    **tab;
	char    *str_env;

	str_env = ft_envto_str(env);
	tab = ft_split(str_env, '\n');
	ft_memdel(str_env);
	ft_sort_env(tab, ft_str_envlen(tab));
	i = 0;
	while (tab[i])
	{
		ft_putstr("declare -x ");
		ft_putendl(tab[i]);
		i++;
	}
	ft_free_tab(tab);
}