#include "minishell.h"

int	ft_issep(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_gnlstrchr("<>|;", line[i]))
		return (0);
	return (ft_gnlstrchr("<>|;", line[i]) && ft_quotes(line, i) == 0);
}

int	ft_ignore_sep(char *line, int i)
{
	if (line[i] == '\\' && line[i + 1] && ft_gnlstrchr(";|><", line[i + 1])
		&& (line[i + 2] == '>' || line[i + 1] != '>'))
		return (1);
	return (0);
}

int	ft_quotes(char *line, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (i < index && line[i])
	{
		if (i > 0 && line[i - 1] != '\\')
		{
			if (open == 0 && (line[i] == '\"' || line[i] == '\''))
			{
				if (line[i] == '\"')
					open = 1;
				else
					open = 2;
			}
			else if ((open == 1 && line[i] == '\"')
				|| (open == 2 && line[i] == '\''))
				open = 0;
		}
		i++;
	}
	return (open);
}

int	ft_islast_validarg(t_token *token)
{
	t_token	*prev;

	prev = ft_sep(token, 0, 0);
	return ((!token || ft_istype(token, CMD) || ft_istype(token, ARG))
		&& (prev && !ft_istype(prev, END) && !ft_istype(prev, PIPE)));
}

int	ft_check_line(t_meta *minishell, t_token *token)
{
	while (token)
	{
		if (ft_istypes(token, "TAI") && (!token->next
				|| ft_istypes(token->next, "TAIPE")))
		{
			if (token->next)
				return (ft_syntax_error(minishell, token->next->str));
			else
				return (ft_syntax_error(minishell, "newline"));
		}
		if (ft_istypes(token, "PE") && (!token->prev || !token->next
				|| ft_istypes(token->prev, "TAIPE")))
			return (ft_syntax_error(minishell, token->str));
		token = token->next;
	}
	return (1);
}
