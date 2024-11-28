/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:47:15 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 01:47:16 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_cderror(char **args)
{
	ft_putstr_fd("cd: ", 2);
	if (args[2])
		ft_putstr_fd("This string is not in pwd", 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(args[1], 2);
}

static char	*ft_get_envpath(t_env *env, const char *var, size_t len)
{
	char	*oldpwd;

	while (env)
	{
		if (ft_strncmp(env->value, var, len) == 0)
		{
			oldpwd = ft_strdup(env->value + len);
			return (oldpwd);
		}
		env = env->next;
	}
	return (NULL);
}

static int	ft_update_pwd_old(t_env *env)
{
	char	*cwd;
	char	*oldpwd;

	cwd = malloc(BUFFER_SIZE + 1);
	if (!cwd || !getcwd(cwd, BUFFER_SIZE + 1))
		return (free(cwd), 1);
	oldpwd = ft_strjoin("OLDPWD = ", cwd);
	if (!oldpwd)
		return (free(cwd), 1);
	if (!ft_is_inenv(env, oldpwd))
		ft_envadd(oldpwd, env);
	if (oldpwd)
	{
		free(cwd);
		free(oldpwd);
		oldpwd = NULL;
	}
	return (0);
}

static int	ft_goto_path(int option, t_env *env)
{
	int		ret;
	char	*env_path;

	env_path = NULL;
	if (option == 0)
	{
		ft_update_pwd_old(env);
		env_path = ft_get_envpath(env, "HOME", 4);
		if (!env_path)
			ft_putendl_fd("MINISHELL: cd: HOME is not yet set", 2);
	}
	else if (option == 1)
	{
		env_path = ft_get_envpath(env, "OLDPWD", 6);
		if (!env_path)
			ft_putendl_fd("MINISHELL: cd: OLDPWD is not yet set", 2);
		ft_update_pwd_old(env);
	}
	if (!env_path)
		return (1);
	ret = chdir(env_path);
	ft_memdel(env_path);
	return (ret);
}

int	ft_b_cd(char **args, t_env *env)
{
	int		cd_ret;

	cd_ret = 0;
	if (!args[1])
		return (ft_goto_path(0, env));
	if (ft_strcmp(args[1], "-") == 0)
		return (ft_goto_path(1, env));
	ft_update_pwd_old(env);
	cd_ret = chdir(args[1]);
	if (cd_ret < 0)
	{
		ft_print_cderror(args);
		cd_ret = 1;
	}
	return (cd_ret);
}
