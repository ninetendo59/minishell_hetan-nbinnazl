#include "minishell.h"

size_t	ft_size_env(t_env *lst)
{
	size_t	len;

	len = 0;
	while (lst && lst->next != NULL)
	{
		if (lst->value != NULL)
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
	while (lst && lst->next != NULL)
	{
		if (lst->value != NULL)
		{
			len = 0;
			while (lst->value[len])
			{
				env[i] = lst->value[len];
				i++;
				len++;
			}
		}
		if (lst->next->next != NULL)
			env[i++] = '\n';
		lst = lst->next;
	}
	env[i] = '\0';
	return (env);
}

int	ft_init_env(t_meta *minishell, char **env_array)
{
	t_env	*curr;
	t_env	*new;
	int		i;

	if (!env_array || !env_array[0])
		return (1);
	curr = malloc(sizeof(t_env));
	if (!curr)
		return (1);
	curr->value = ft_strdup(env_array[0]);
	curr->next = NULL;
	minishell->env = curr;
	i = 1;
	while (env_array && env_array[0] && env_array[i])
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (1);
		new->value = ft_strdup(env_array[i]);
		new->next = NULL;
		curr->next = new;
		curr = new;
		i++;
	}
	return (0);
}

int	ft_init_secret_env(t_meta *minishell, char **env_array)
{
	t_env	*curr;
	t_env	*new;
	int		i;

	if (!env_array || !env_array[0])
		return (1);
	curr = malloc(sizeof(t_env));
	if (!curr)
		return (1);
	curr->value = ft_strdup(env_array[0]);
	curr->next = NULL;
	minishell->secret_env = curr;
	i = 1;
	while (env_array && env_array[0] && env_array[i])
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (1);
		new->value = ft_strdup(env_array[i]);
		new->next = NULL;
		curr->next = new;
		curr = new;
		i++;
	}
	return (0);
}
