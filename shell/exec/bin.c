/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:53:25 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 03:34:21 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_message(char *path)
{
	DIR	*folder;
	int	fd;
	int	ret;

	fd = open(path, O_WRONLY);
	folder = opendir(path);
	ft_putstr_fd("MINISHELL: ", 2);
	ft_putstr_fd(path, 2);
	if (ft_strchr(path, '/') == NULL)
		ft_putendl_fd(": command not found", 2);
	else if (fd == -1 && folder == NULL)
		ft_putendl_fd(": No such file or directory", 2);
	else if (fd == -1 && folder != NULL)
		ft_putendl_fd(": is a directory", 2);
	else if (fd != -1 && folder == NULL)
		ft_putendl_fd(": Permission denied", 2);
	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
		ret = 127;
	else
		ret = 126;
	if (folder)
		closedir(folder);
	ft_close(fd);
	return (ret);
}

int	ft_mgc_box(char *path, char **args, t_env *env, t_meta *mini)
{
	char	**env_array;
	char	*ptr;
	int		ret;

	ret = 0;
	g_sig.pid = fork();
	if (g_sig.pid == 0)
	{
		ptr = ft_envto_str(env);
		env_array = ft_split(ptr, '\n');
		ft_memdel(ptr);
		if (ft_strchr(path, '/') != NULL)
			execve(path, args, env_array);
		ret = error_message(path);
		ft_free_tab(env_array);
		ft_free_token(mini->start);
		exit(ret);
	}
	else
		waitpid(g_sig.pid, &ret, 0);
	return (handle_signal_and_return(ret));
}

static char	*ft_path_join(const char *s1, const char *s2)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	ft_memdel(tmp);
	return (path);
}

char	*ft_check_dir(char *bin, char *command)
{
	DIR				*folder;
	struct dirent	*item;
	char			*path;

	path = NULL;
	folder = opendir(bin);
	if (!folder)
		return (NULL);
	item = readdir(folder);
	while ((item))
	{
		if (ft_strcmp(item->d_name, command) == 0)
			path = ft_path_join(bin, item->d_name);
		item = readdir(folder);
	}
	closedir(folder);
	return (path);
}

int	ft_exec_bin(char **args, t_env *env, t_meta *mini)
{
	int		i;
	char	**bin;
	char	*path;
	int		ret;

	i = 0;
	ret = 127;
	while (env && env->value && ft_strncmp(env->value, "PATH=", 5) != 0)
		env = env->next;
	if (env == NULL || env->next == NULL)
		return (ft_mgc_box(args[0], args, env, mini));
	bin = ft_split(env->value, ':');
	if (!args[0] && !bin[0])
		return (1);
	i = 1;
	path = ft_check_dir(bin[0] + 5, args[0]);
	while (args[0] && bin[i] && path == NULL)
		path = ft_check_dir(bin[i++], args[0]);
	if (path != NULL)
		ret = ft_mgc_box(path, args, env, mini);
	else
		ret = ft_mgc_box(args[0], args, env, mini);
	ft_free_tab(bin);
	ft_memdel(path);
	return (ret);
}
