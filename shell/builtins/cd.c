#include "minishell.h"

static void ft_print_cderror(char **args)
{
	ft_putstr_fd("cd: ", 2);
	if (args[2])
		ft_putstr_fd("This string is not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(args[1], 2);
}

static char	*ft_get_envpath(t_env *env, const char *var, size_t len)
{
	char	*oldpwd;
	int		i;
	int		j;
	int		alloc;

	while (env && env->next != NULL)
	{
		if (ft_strncmp(env->value, var, len) == 0)
		{
			alloc = ft_strlen(env->value) - len;
			if (!(oldpwd = malloc(sizeof(char) * alloc + 1)))
				return (NULL);
			i = 0;
			j = 0;
			while (env->value[i++])
			{
				if (i > (int)len)
					oldpwd[j++] = env->value[i];
			}
			oldpwd[j] = '\0';
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

	cwd = malloc(sizeof(*cwd) * (BUFFER_SIZE + 1));
	if (!cwd)
		return (free(cwd), 1);

    if (getcwd(cwd, BUFFER_SIZE + 1) == NULL)
		return (free(cwd), 1);
	if (!(oldpwd = ft_strjoin("OLDPWD = ", cwd)))
		return (free(cwd), 1);
	if (ft_is_inenv(env, oldpwd) == 0)
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
		if (!env_path)
			return (1);
	}
	else if (option == 1)
	{
		env_path = ft_get_envpath(env, "OLDPWD", 6);
		if (!env_path)
			ft_putendl_fd("MINISHELL: cd: OLDPWD is not yet set", 2);
		if (!env_path)
			return (1);
		ft_update_pwd_old(env);
	}
	ret = chdir(env_path);
	ft_memdel(env_path);
	return (ret);
}

int ft_b_cd(char **args, t_env *env)
{
	int		cd_ret;

	if (!args[1])
		return (ft_goto_path(0, env));
	if (ft_strcmp(args[1], "-") == 0)
		cd_ret = ft_goto_path(1, env);
	else
	{
		ft_update_pwd_old(env);
		cd_ret = chdir(args[1]);
		if (cd_ret < 0)
			cd_ret *= -1;
		if (cd_ret != 0)
			ft_print_cderror(args);
	}
	return (cd_ret);
}

// int	main(int argc, char **argv, char **env)
// {
// 	t_meta	dat;
// 	// (void)argc;
// 	// (void)argv;
// 	int	result = 0;

// 	ini_list(&dat);
// 	ft_init_env(&dat, env);
// 	if (argc > 0)
// 	{
// 		if (ft_strcmp(argv[1], "cd") == 0)
//         {
// 			argv++;
// 			result = ft_b_cd(argv, dat.env);
// 			printf("%d", result);
//        }
// 	}
// 	return (result);
// }