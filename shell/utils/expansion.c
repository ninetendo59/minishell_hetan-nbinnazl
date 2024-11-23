#include "minishell.h"

static int	ft_ret_size(int ret)
{
	char	*tmp;
	int		ret_len;

	tmp = ft_itoa(ret);
	ret_len = ft_strlen(tmp);
	ft_memdel(tmp);
	return (ret_len);
}

static int	ft_get_varlen(const char *arg, int pos, t_env *env, int ret)
{
	char	var_name[BUFFER_SIZE];
	char	*var_value;
	int		len;

	len = 0;
	if (arg[pos] == '?')
		return (ft_ret_size(ret));
	if (ft_isdigit(arg[pos]))
		return (0);
	while (arg[pos] && ft_isenv_char(arg[pos]) && len < BUFFER_SIZE)
		var_name[len++] = arg[pos++];
	var_name[len] = '\0';
	var_value = ft_getenv_value(var_name, env);
	len = ft_strlen(var_value);
	ft_memdel(var_value);
	return (len);
}

int	ft_arg_alloclen(const char *arg, t_env *env, int ret)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (arg[i])
	{
		if (arg[i] == -36)
		{
			i++;
			if ((!arg[i] || !ft_isalnum(arg[i])) && arg[i] != '?')
				size++;
			else
				size += ft_get_varlen(arg, i, env, ret);
			if (!ft_isdigit(arg[i]))
				while (arg[i + 1] && ft_isenv_char(arg[i]))
					i++;
		}
		size++;
		i++;
	}
	return (size);
}

char	*ft_get_varvalue(const char *arg, int pos, t_env *env, int ret)
{
	char	var_name[BUFFER_SIZE];
	int		len;

	len = 0;
	if (arg[pos] == '?')
		return (ft_itoa(ret));
	if (ft_isdigit(arg[pos]))
		return (NULL);
	while (arg[pos] && ft_isenv_char(arg[pos]) && len < BUFFER_SIZE)
		var_name[len++] = arg[pos++];
	var_name[len] = '\0';
	return (ft_getenv_value(var_name, env));
}