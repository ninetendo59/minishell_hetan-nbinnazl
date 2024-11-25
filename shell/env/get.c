#include "minishell.h"

int	ft_isenv_char(int c)
{
	return (ft_isalnum(c) || c == '_');
}

int	ft_isvalid_env(const char *env)
{
	int	i;

	i = 0;
	if (ft_isdigit(env[i]) == 1)
		return (0);
	while (env[i] && env[i] != '=')
	{
		if (ft_isalnum(env[i]) == 0)
			return (-1);
		i++;
	}
	if (env[i] == '=')
		return (1);
	return (2);
}

int	ft_envvalue_len(const char *env)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	while (env[i] && env[i] != '=')
		i++;
	i += 1;
	while (env[i])
	{
		i++;
		size++;
	}
	return (size);
}

char	*ft_envvalue(char *env)
{
	int		i;
	int		j;
	int		size;
	char	*value;

	i = 0;
	size = ft_envvalue_len(env) + 1;
	value = malloc(size);
	if (!value)
		return (NULL);
	while (env[i] && env[i] != '=')
		i++;
	i += 1;
	j = 0;
	while (env[i])
		value[j++] = env[i++];
	value[j] = '\0';
	return (value);
}

char	*ft_getenv_value(char *arg, t_env *env)
{
	char	env_name[BUFFER_SIZE];
	char	*env_val;

	env_val = ft_strdup("");
	while (env && env->value)
	{
		ft_get_envname(env_name, env->value);
		if (ft_strcmp(arg, env_name) == 0)
		{
			ft_memdel(env_val);
			env_val = ft_envvalue(env->value);
			return (env_val);
		}
		env = env->next;
	}
	return (env_val);
}
