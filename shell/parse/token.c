#include "minishell.h"

static int	ft_next_alloc(char *line, int *i)
{
	int		count;
	int		j;
	char	c;

	count = 0;
	j = 0;
	c = ' ';
	while (line[*i + j] && (line[*i + j] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i + j] == '\'' || line[*i + j] == '\"'))
			c = line[*i + j++];
		else if (c != ' ' && line[*i + j] == c)
		{
			count += 2;
			c = ' ';
			j++;
		}
		else
			j++;
		if (line[*i + j - 1] == '\\')
			count--;
	}
	return (j - count + 1);
}

static t_token	*ft_next_token(char *line, int *i)
{
	t_token	*token;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = malloc(ft_next_alloc(line, i));
	if (!(token->str))
		return (NULL);
	while (line[*i] && (line[*i] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			c = line[(*i)++];
		else if (c != ' ' && line[*i] == c)
		{
			c = ' ';
			(*i)++;
		}
		else if (line[*i] == '\\' && (*i)++)
			token->str[j++] = line[(*i)++];
		else
			token->str[j++] = line[(*i)++];
	}
	token->str[j] = '\0';
	return (token);
}

void	ft_type_arg(t_token *token, int separator)
{
	if (*token->str == '\0')
		token->type = EMPTY;
	else if (separator == 0)
	{
		if (ft_strcmp(token->str, ">") == 0)
			token->type = TRUNC;
		else if (ft_strcmp(token->str, ">>") == 0)
			token->type = APPEND;
		else if (ft_strcmp(token->str, "<") == 0)
			token->type = INPUT;
		else if (ft_strcmp(token->str, "|") == 0)
			token->type = PIPE;
		else if (ft_strcmp(token->str, ";") == 0)
			token->type = END;
	}
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}

void	ft_squish_args(t_meta *minishell)
{
	t_token	*token;
	t_token	*prev;

	token = minishell->start;
	while (token)
	{
		prev = ft_sep(token, 0, 0);
		if (ft_istype(token, ARG) && ft_istypes(prev, "TAI"))
		{
			while (!ft_islast_validarg(prev))
				prev = prev->prev;
			token->prev->next = token->next;
			if (token->next)
				token->next->prev = token->prev;
			token->prev = prev;
			if (prev)
				token->next = prev->next;
			else
				token->next = minishell->start;
			if (!prev)
				prev = token;
			prev->next->prev = token;
			if (minishell->start->prev)
				prev->next = prev->next;
			else
				prev->next = token;
			if (minishell->start->prev)
				minishell->start = minishell->start->prev;
			else
				minishell->start = minishell->start;
		}
		token = token->next;
	}
}

t_token	*ft_get_tokens(char *line)
{
	t_token	*prev;
	t_token	*next;
	int		i;
	int		sep;

	i = 0;
	prev = NULL;
	next = NULL;
	if (!line)
		return (NULL);
	ft_skip_whitespace(line, &i);
	while (line[i])
	{
		sep = ft_ignore_sep(line, i);
		next = ft_next_token(line, &i);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		ft_type_arg(next, sep);
		ft_skip_whitespace(line, &i);
	}
	if (next)
		next->next = NULL;
	while (next && next->prev)
		next = next->prev;
	return (next);
}
