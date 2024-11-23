#include "minishell.h"

t_token	*ft_sep(t_token *token, int skip, int next)
{
	if (next)
	{
		if (token && skip)
			token = token->next;
		while (token && token->type < TRUNC)
			token = token->next;
	}
	if (!next)
	{
		if (token && skip)
			token = token->prev;
		while (token && token->type < TRUNC)
			token = token->prev;
	}
	return (token);
}

t_token	*ft_next_run(t_token *token, int skip)
{
	if (token && skip)
		token = token->next;
	while (token && token->type != CMD)
		token = token->next;
	if (token && token->prev && token->prev->type < END)
		token = token->next;
	return (token);
}

void	ft_update_links(t_meta *minishell, t_token *token, t_token *prev)
{
	if (prev)
		token->next = prev->next;
	else
		token->next = minishell->start;
	if (prev && prev->next)
		prev->next->prev = token;
	if (!prev)
		minishell->start = token;
	else
		prev->next = token;
}

void	ft_process_token(t_token **prev, t_token *next, int sep)
{
	if (next)
	{
		next->prev = *prev;
		if (*prev)
			(*prev)->next = next;
		*prev = next;
		ft_type_arg(next, sep);
	}
}

void	ft_reset_quote(char *c, int *i)
{
	*c = ' ';
	(*i)++;
}
