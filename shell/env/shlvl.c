/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:48:38 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 01:48:39 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ft_lvl_invalid(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

void	ft_lvl_increment(t_env *env)
{
	char	*shlvl;
	char	*shlvl_value;
	char	env_name[BUFFER_SIZE];
	int		shell_level;

	shlvl_value = ft_getenv_value("SHLVL", env);
	if (ft_strcmp(shlvl_value, "") == 0)
		return ;
	shell_level = ft_lvl_get(shlvl_value) + 1;
	ft_memdel(shlvl_value);
	while (env && env->next)
	{
		ft_get_envname(env_name, env->value);
		if (ft_strcmp("SHLVL", env_name) == 0)
		{
			ft_memdel(env->value);
			shlvl = ft_itoa(shell_level);
			env->value = ft_strjoin("SHLVL=", shlvl);
			ft_memdel(shlvl);
			return ;
		}
		env = env->next;
	}
}
