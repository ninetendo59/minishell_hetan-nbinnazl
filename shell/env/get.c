#include "minishell.h"

int	ft_isenv_char(int c)
{
	return (ft_isalnum(c) || c == '_');
}

int	ft_isvalid_env(const char *env)
{
	int	i;

	i = 0;
	if (ft_isdigit(env[0]))
		return (0);
	while (env[i] && env[i] != '=')
	{
		if (!ft_isenv_char(env[i]))
			return (-1);
		i++;
	}
	if (env[i] == '=')
		return (1);
	return (2);
}

int	ft_envvalue_len(const char *env)
{
	const char	*value;

	value = ft_gnlstrchr(env, '=');
	if (value)
		return (ft_strlen(value + 1));
	return (0);
}

char	*ft_envvalue(const char *env)
{
	const char	*value;

	value = ft_gnlstrchr(env, '=');
	if (value)
		return (ft_strdup(value + 1));
	return (NULL);
}

char	*ft_getenv_value(const char *arg, t_env *env)
{
	char	env_name[BUFFER_SIZE];

	while (env && env->value)
	{
		ft_get_envname(env_name, env->value);
		if (ft_strcmp(arg, env_name) == 0)
			return (ft_envvalue(env->value));
		env = env->next;
	}
	return (ft_strdup(""));
}
