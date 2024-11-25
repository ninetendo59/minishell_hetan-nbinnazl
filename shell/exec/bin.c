#include "minishell.h"

int	ft_error_msg(char *path)
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
	else if (fd == -1)
	{
		if (folder == NULL)
			ft_putendl_fd(": There is no such file or directory", 2);
		else if (folder != NULL)
			ft_putendl_fd(": is a directory", 2);
	}
	else if (fd == -1 && folder == NULL)
		ft_putendl_fd(": Permission denied", 2);
	ret = 126;
	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
		ret = 127;
	if (folder)
		closedir(folder);
	ft_close(fd);
	return (ret);
}

int	ft_mgc_box(char *path, char **args, t_env *env, t_meta *minishell)
{
	char	**env_array;
	char	*env_str;
	int		ret;

	ret = 0;
	g_sig.pid = fork();
	if (g_sig.pid == 0)
	{
		env_str = ft_envto_str(env);
		env_array = ft_split(env_str, '\n');
		ft_memdel(env_str);
		if (ft_strchr(path, '/') != NULL)
			execve(path, args, env_array);
		ret = ft_error_msg(path);
		ft_free_tab(env_array);
		ft_free_token(minishell->start);
		exit(ret);
	}
	else
		waitpid(g_sig.pid, &ret, 0);
	if (g_sig.sigint == 1 || g_sig.sigquit == 1)
		return (g_sig.exit_stat);
	if (ret == 32256 || ret == 32512)
		return (ret / 256);
	return (!!ret);
}

char	*ft_join_path(const char *s1, const char *s2)
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
	while (item)
	{
		if (ft_strcmp(item->d_name, command) == 0)
			path = ft_join_path(bin, item->d_name);
	}
	closedir(folder);
	return (path);
}

int	ft_exec_bin(char **args, t_env *env, t_meta *minishell)
{
	char	**bin;
	char	*path;
	int		ret;
	int		i;

	i = 0;
	ret = 127;
	// path = NULL;
	while (env && env->value && ft_strncmp(env->value, "PATH=", 5) != 0)
		env = env->next;
	if (env == NULL || env->next == NULL)
		return (ft_mgc_box(args[0], args, env, minishell));
	bin = ft_split(env->value, ':');
	if (!args[0] && !bin[0])
		return (1);
	i = 1;
	path = ft_check_dir(bin[0] + 5, args[0]);
	while (args[0] && bin[i] && path == NULL)
		path = ft_check_dir(bin[i++], args[0]);
	if (path != NULL)
		ret = ft_mgc_box(path, args, env, minishell);
	else
		ret = ft_mgc_box(args[0], args, env, minishell);
	ft_free_tab(bin);
	ft_memdel(path);
	return (ret);
}
