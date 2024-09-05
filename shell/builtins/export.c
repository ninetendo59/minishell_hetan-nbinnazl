#include "minishell.h"

static int	ft_print_errorexp(int error, const char *arg)
{
	int		i;

	if (error == -1)
		ft_putstr_fd("export: It is not valid in this context: ", 2);
	else if (error == 0 || error == -3)
		ft_putstr_fd("export: It is not a valid identifier: ", 2);
	i = 0;
	while (arg[i] && (arg[i] != '=' || error == -3))
	{
		write(2, &arg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	return (1);
}

char	*ft_get_envname(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '=' && ft_strlen(src) < BUFFER_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_envadd(const char *value, t_env *env)
{
	t_env	*new;
	t_env	*tmp;

	if (env && env->value == NULL)
	{
		env->value = ft_strdup(value);
		return (0);
	}
	if (!(new = malloc(sizeof(t_env))))
		return (-1);
	new->value = ft_strdup(value);
	while (env && env->next && env->next->next)
		env = env->next;
	tmp = env->next;
	env->next = new;
	new->next = tmp;
	return (0);
}

int	ft_is_inenv(t_env *env, char *args)
{
	char	*var_name;
	char	*env_name;

	var_name = malloc(sizeof(*var_name) * (BUFFER_SIZE + 1));
	if (!var_name)
		return (free(var_name), 1);

	env_name = malloc(sizeof(*env_name) * (BUFFER_SIZE + 1));
	if (!env_name)
		return (free(env_name), 1);

	ft_get_envname(var_name, args);
	while (env && env->next)
	{
		ft_get_envname(env_name, env->value);
		if (ft_strcmp(var_name, env_name) == 0)
		{
			ft_memdel(env->value);
			env->value = ft_strdup(args);
			return (1);
		}
		env = env->next;
	}
	return (free(var_name), free(env_name), 0);
}

int			ft_b_export(char **args, t_env *env, t_env *secret)
{
	int		new_env;
	int		error_ret;

	new_env = 0;
	if (!args[1])
	{
		ft_print_sortedenv(secret);
		return (0);
	}
	else
	{
		error_ret = ft_isvalid_env(args[1]);
		if (args[1][0] == '=')
			error_ret = -3;
		if (error_ret <= 0)
			return (ft_print_errorexp(error_ret, args[1]));
		new_env = error_ret == 2 ? 1 : ft_is_inenv(env, args[1]);
		if (new_env == 0)
		{
			if (error_ret == 1)
				ft_envadd(args[1], env);
			ft_envadd(args[1], secret);
		}
	}
	return (0);
}