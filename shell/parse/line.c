#include "minishell.h"

static char	*ft_alloc_with_spaces(char *line)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
		count += ft_issep(line, i++);
	return (malloc(i + 2 * count + 1));
}

static char	*ft_proc_spaces(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_alloc_with_spaces(str);
	while (new && str[i])
	{
		if (ft_quotes(str, i) != 2 && str[i] == '$' && i && str[i - 1] != '\\')
			new[j++] = (char)(-str[i++]);
		else if (ft_quotes(str, i) == 0 && ft_issep(str, i))
		{
			new[j++] = ' ';
			new[j++] = str[i++];
			if (ft_quotes(str, i) == 0 && str[i] == '>')
				new[j++] = str[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = str[i++];
	}
	if (new)
		new[j] = '\0';
	// return (ft_memdel(str), new);
	return (new);
}

static int	ft_check_quotes(t_meta *minishell, char *line)
{
	if (ft_quotes(line, INT_MAX))
	{
		ft_putendl_fd("minishell: syntax error with open quotes", 2);
		// ft_memdel(line);
		minishell->ret = 2;
		minishell->start = NULL;
		return (1);
	}
	return (0);
}

static void	ft_process_tokens(t_meta *minishell, char *line)
{
	t_token	*token;

	line = ft_proc_spaces(line);
	if (line && line[0] == '$')
		line[0] = (char)(-line[0]);
	minishell->start = ft_get_tokens(line);
	ft_squish_args(minishell);
	token = minishell->start;
	while (token)
	{
		if (ft_istype(token, ARG))
			ft_type_arg(token, 0);
		token = token->next;
	}
	ft_memdel(line);
}

void	ft_parse_input(t_meta *minishell)
{
	// char	*line;

	// line = NULL;
	signal(SIGINT, &ft_sig_int);
	signal(SIGQUIT, &ft_sig_quit);
	if (minishell->ret)
		ft_putstr_fd("🟢 ", 2);
	else
		ft_putstr_fd("🔴 ", 2);
	ft_putstr_fd("\033[0;36m\033[1mminishell ▸ \033[0m", 2);
	minishell->exit = 1;
	//if (ft_get_next_line(0, &line) == -2 && minishell->exit)
	if (!(minishell->cmd) && minishell->exit)
	{
		ft_putendl_fd("exit", 2);
		return ;
	}
	if (g_sig.sigint == 1)
		minishell->ret = g_sig.exit_stat;
	else
		minishell->ret = minishell->ret;
	if (ft_check_quotes(minishell, minishell->cmd))
		return ;
	ft_process_tokens(minishell, minishell->cmd);
}
