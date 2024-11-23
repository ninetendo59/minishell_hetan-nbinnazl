#include "minishell.h"

static int	ft_copy_envvalue(char *new_arg, const char *env_value, int pos)
{
	int	i;

	i = 0;
	while (env_value[i])
		new_arg[pos++] = env_value[i++];
	return (i);
}

static void	ft_insert_var(t_exp *ex, char *arg, t_env *env, int ret)
{
	char	*env_value;

	env_value = ft_get_varvalue(arg, ex->j, env, ret);
	if (env_value)
		ex->i += ft_copy_envvalue(ex->new_arg, env_value, ex->i);
	ft_memdel(env_value);
	if (arg[ex->j] == '?')
		ex->j++;
	else if (!ft_isdigit(arg[ex->j]) && arg[ex->j - 1] != '?')
		while (ft_isenv_char(arg[ex->j]))
			ex->j++;
	else if (arg[ex->j - 1] != '?')
		ex->j++;
}

char	*ft_expansions(char *arg, t_env *env, int ret)
{
	t_exp	ex;
	int		new_arg_len;

	new_arg_len = ft_arg_alloclen(arg, env, ret);
	ex.new_arg = malloc(new_arg_len + 1);
	if (!ex.new_arg)
		return (NULL);
	ex.i = 0;
	ex.j = 0;
	while (ex.i < new_arg_len && arg[ex.j])
	{
		if (arg[ex.j] == -36)
		{
			ex.j++;
			if (!arg[ex.j] || (!ft_isalnum(arg[ex.j]) && arg[ex.j] != '?'))
				ex.new_arg[ex.i++] = '$';
			else
				ft_insert_var(&ex, arg, env, ret);
		}
		else
			ex.new_arg[ex.i++] = arg[ex.j++];
	}
	ex.new_arg[ex.i] = '\0';
	return (ex.new_arg);
}
