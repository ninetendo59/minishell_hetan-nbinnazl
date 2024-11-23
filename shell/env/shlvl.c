#include "minishell.h"

static int	ft_lvl_invalid(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		else
			str++;
	}
	return (0);
}

static int	ft_lvl_get(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	ft_skip_whitespace(str, &i);
	if (ft_lvl_invalid(&str[i]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	ft_lvl_increment(t_env *env)
{
	char	*shell_level_value;
	char	env_name[BUFFER_SIZE];
	int		shell_level;

	shell_level_value = ft_getenv_value("SHLVL", env);
	if (shell_level_value && *shell_level_value)
	{
		shell_level = ft_lvl_get(shell_level_value) + 1;
		ft_memdel(shell_level_value);
		while (env)
		{
			ft_get_envname(env_name, env->value);
			if (ft_strcmp("SHLVL", env_name) == 0)
			{
				ft_memdel(env->value);
				env->value = ft_strjoin("SHLVL=", ft_itoa(shell_level));
				return ;
			}
			env = env->next;
		}
	}
}
