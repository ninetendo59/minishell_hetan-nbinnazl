/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:18:41 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 02:18:42 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_copy_envvalue(char *new_arg, const char *env_value, int pos)
{
	int	i;

	i = 0;
	while (env_value[i])
		new_arg[pos++] = env_value[i++];
	return (i);
}

static void	ft_insert_var(t_exp *exp, char *arg, t_env *env, int ret)
{
	char	*env_value;

	env_value = ft_get_varvalue(arg, exp->j, env, ret);
	if (env_value)
		exp->i += ft_copy_envvalue(exp->new_arg, env_value, exp->i);
	ft_memdel(env_value);
	if (arg[exp->j] == '?')
		exp->j++;
	if (ft_isdigit(arg[exp->j]) == 0 && arg[exp->j - 1] != '?')
	{
		while (ft_isenv_char(arg[exp->j]) == 1)
			exp->j++;
	}
	else
	{
		if (arg[exp->j - 1] != '?')
			exp->j++;
	}
}

char	*ft_expansions(char *arg, t_env *env, int ret)
{
	t_exp	exp;
	int		new_arg_len;

	exp.i = 0;
	exp.j = 0;
	new_arg_len = ft_arg_alloclen(arg, env, ret);
	exp.new_arg = malloc(new_arg_len + 1);
	if (!exp.new_arg)
		return (NULL);
	while (exp.i < new_arg_len && arg[exp.j])
	{
		while (arg[exp.j] == -36)
		{
			exp.j++;
			if (arg[exp.j] != '?' && (arg[exp.j] == '\0'
					|| ft_isalnum(arg[exp.j]) == 0))
				exp.new_arg[exp.i++] = '$';
			else
				ft_insert_var(&exp, arg, env, ret);
		}
		exp.new_arg[exp.i++] = arg[exp.j++];
	}
	exp.new_arg[exp.i] = '\0';
	return (exp.new_arg);
}
