/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:47:32 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 01:47:33 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_print_errorexp(int error, const char *arg)
{
	if (error == -1)
		ft_putstr_fd("export: It is not valid in this context: ", 2);
	else if (error == 0 || error == -3)
		ft_putstr_fd("export: It is not a valid identifier: ", 2);
	while (*arg && (*arg != '=' || error == -3))
		write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

char	*ft_get_envname(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '=' && i < BUFFER_SIZE)
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

	if (env && !env->value)
	{
		env->value = ft_strdup(value);
		return (0);
	}
	new = malloc(sizeof(t_env));
	if (!new)
		return (-1);
	new->value = ft_strdup(value);
	new->next = env->next;
	env->next = new;
	return (0);
}

int	ft_is_inenv(t_env *env, char *args)
{
	char	var_name[BUFFER_SIZE + 1];
	char	env_name[BUFFER_SIZE + 1];

	ft_get_envname(var_name, args);
	while (env)
	{
		ft_get_envname(env_name, env->value);
		if (ft_strcmp(var_name, env_name) == 0)
		{
			free(env->value);
			env->value = ft_strdup(args);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

int	ft_b_export(char **args, t_env *env, t_env *secret)
{
	int		error_ret;

	if (!args[1])
		return (ft_print_sortedenv(secret), 0);
	error_ret = ft_isvalid_env(args[1]);
	if (args[1][0] == '=')
		error_ret = -3;
	if (error_ret <= 0)
		return (ft_print_errorexp(error_ret, args[1]));
	if (error_ret != 2 && ft_is_inenv(env, args[1]))
		return (0);
	ft_envadd(args[1], env);
	ft_envadd(args[1], secret);
	return (0);
}
