#include "minishell.h"

size_t	ft_size_env(t_env *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		if (lst->value)
			len += ft_strlen(lst->value) + 1;
		lst = lst->next;
	}
	return (len);
}

char	*ft_envto_str(t_env *lst)
{
	char	*env;
	int		i;
	size_t	len;

	env = malloc(ft_size_env(lst) + 1);
	if (!env)
		return (NULL);
	i = 0;
	while (lst)
	{
		if (lst->value)
		{
			len = ft_strlen(lst->value);
			ft_strlcpy(&env[i], lst->value, len + 1);
			i += len;
		}
		if (lst->next)
			env[i++] = '\n';
		lst = lst->next;
	}
	env[i] = '\0';
	return (env);
}

int	ft_init_env(t_meta *minishell, char **env_array)
{
	t_env	*curr;
	int		i;

	if (!env_array || !env_array[0])
		return (1);
	curr = minishell->env;
	i = 0;
	while (env_array && env_array[i])
	{
		curr = malloc(sizeof(t_env));
		if (!(curr))
			return (1);
		curr->value = ft_strdup(env_array[i]);
		if (!curr->value)
			return (free(curr), 1);
		// curr->next = NULL;
		curr = curr->next;
		i++;
	}
	curr = NULL;
	return (0);
}

int	ft_init_secret_env(t_meta *minishell, char **env_array)
{
	t_env	**curr;
	int		i;

	if (!env_array || !env_array[0])
		return (1);
	curr = &minishell->secret_env;
	i = 0;
	while (env_array && env_array[i])
	{
		*curr = malloc(sizeof(t_env));
		if (!(*curr))
			return (1);
		(*curr)->value = ft_strdup(env_array[i]);
		if (!(*curr)->value)
			return (free(*curr), 1);
		(*curr)->next = NULL;
		curr = &(*curr)->next;
		i++;
	}
	return (0);
}
