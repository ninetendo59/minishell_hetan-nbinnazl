#include "minishell.h"

static char	*ft_alloc_with_spaces(char *line)
{
	int		i;
	int		count;
	char	*new;

	i = 0;
	count = 0;
	if (!line)
		return (NULL);
	while (line[i])
	{
		if (ft_issep(line, i))
			count++;
		i++;
	}
	new = malloc((i + 2 * count + 1));
	if (!new)
		return (NULL);
	return (new);
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
		else if (ft_issep(str, i) && ft_quotes(str, i) == 0)
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
	new[j] = '\0';
	ft_memdel(str);
	return (new);
}

static int	ft_check_quotes(t_meta *minishell, char **line)
{
	if (ft_quotes(*line, INT_MAX))
	{
		ft_putendl_fd("MINISHELL: syntax error with open quotes", 2);
		ft_memdel(*line);
		minishell->ret = 2;
		minishell->start = NULL;
		return (1);
	}
	return (0);
}

// void	ft_parse_input(t_meta *minishell)
// {
// 	char	*line;
// 	t_token	*token;

// 	signal(SIGINT, &ft_sig_int);
// 	signal(SIGQUIT, &ft_sig_quit);
// 	if (minishell->ret)
// 		ft_putstr_fd("🔴 ", 2);
// 	else
// 		ft_putstr_fd("🟢 ", 2);
// 	ft_putstr_fd("\033[0;36m\033[1mMINISHELL: \033[0m", 2);
// 	if (ft_get_next_line(0, &line) == -2)
// 	{
// 		minishell->exit = 1;
// 		ft_putendl_fd("exit", 2);
// 	}
// 	if (g_sig.sigint == 1)
// 		minishell->ret = g_sig.exit_stat;
// 	if (ft_check_quotes(minishell, &line))
// 		return ;
// 	line = ft_proc_spaces(line);
// 	if (line && line[0] == '$')
// 		line[0] = (char)(-line[0]);
// 	minishell->start = ft_get_tokens(line);
// 	ft_memdel(line);
// 	ft_squish_args(minishell);
	
// 	token = minishell->start;
// 	while (token)
// 	{
// 		if (ft_istype(token, ARG))
// 			ft_type_arg(token, 0);
// 		token = token->next;
// 	}
// }


// void	ft_parse_input(t_meta *minishell)
// {
// 	char			*line;
// 	t_token			*token;

// 	signal(SIGINT, &ft_sig_int);
// 	signal(SIGQUIT, &ft_sig_quit);

// 	if (minishell->ret)
// 		ft_putstr_fd("🔴 \033[0;36m\033[1mMINISHELL ▸ \033[0m", 2);
// 	else
// 		ft_putstr_fd("🟢 \033[0;36m\033[1mMINISHELL ▸ \033[0m", 2);
// 	line = readline("");
// 	if (!line)
// 	{
// 		minishell->exit = 1;
// 		ft_putendl_fd("exit", 2);
// 		return;
// 	}
// 	if (*line)
// 		add_history(line);
// 	if (g_sig.sigint == 1)
// 		minishell->ret = g_sig.exit_stat;
// 	if (ft_check_quotes(minishell, &line))
// 		return;
// 	line = ft_proc_spaces(line);
// 	if (line && line[0] == '$')
// 		line[0] = (char)(-line[0]);
// 	minishell->start = ft_get_tokens(line);
// 	ft_memdel(line);
// 	ft_squish_args(minishell);
// 	token = minishell->start;
// 	while (token)
// 	{
// 		if (ft_istype(token, ARG))
// 			ft_type_arg(token, 0);
// 		token = token->next;
// 	}
// }

void	ft_parse_input(t_meta *minishell)
{
	t_token			*token;
	// char			*prompt;

	minishell->cmd = NULL;
	// prompt = NULL;
	signal(SIGINT, &ft_sig_int);
	signal(SIGQUIT, &ft_sig_quit);
	// 	prompt = "\033[0;31m🔴 \033[0;36m\033[1mMINISHELL: \033[0m";
	// else
	if (!minishell->ret)
		write(1, "\033[0;32m🟢", ft_strlen("\033[0;32m🟢"));
	else
		write(1, "\033[0;31m🔴 ", ft_strlen("\033[0;31m🔴"));
	if (g_sig.sigint == 1)
		minishell->ret = 1;
	minishell->cmd = readline("\033[0;36m\033[1mMINISHELL: \033[0m");
	// line = readline(prompt);
	if (!minishell->cmd)
	{
		// ft_putstr_fd("\033[2K\rexit\n", 2);
		minishell->exit = 1;
		// ft_putstr_fd("\b\b", 2);
		ft_putendl_fd("\nexit", 2);
		
		return;
	}
	if (*minishell->cmd)
		add_history(minishell->cmd);
	if (g_sig.sigint == 1)
		minishell->ret = g_sig.exit_stat;
	if (ft_check_quotes(minishell, &(minishell->cmd)))
		return;
	minishell->cmd = ft_proc_spaces(minishell->cmd);
	if (minishell->cmd && *minishell->cmd == '$')
		*minishell->cmd = (char)(-*minishell->cmd);
	minishell->start = ft_get_tokens(minishell->cmd);
	ft_memdel(minishell->cmd);
	ft_squish_args(minishell);
	token = minishell->start;
	while (token)
	{
		if (ft_istype(token, ARG))
			ft_type_arg(token, 0);
		token = token->next;
	}
}
