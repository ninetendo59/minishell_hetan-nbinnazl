/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:08:53 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 03:38:07 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_type_arg(t_token *token, int separator)
{
	if (ft_strcmp(token->str, "") == 0)
		token->type = EMPTY;
	else if (separator == 0 && ft_strcmp(token->str, ">") == 0)
		token->type = TRUNC;
	else if (separator == 0 && ft_strcmp(token->str, ">>") == 0)
		token->type = APPEND;
	else if (separator == 0 && ft_strcmp(token->str, "<") == 0)
		token->type = INPUT;
	else if (separator == 0 && ft_strcmp(token->str, "|") == 0)
		token->type = PIPE;
	else if (separator == 0 && ft_strcmp(token->str, ";") == 0)
		token->type = END;
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}

void	ft_squish_args(t_meta *mini)
{
	t_token	*token;
	t_token	*prev;

	token = mini->start;
	while (token)
	{
		prev = ft_sep(token, 0, 0);
		if (ft_istype(token, ARG) && ft_istypes(prev, "TAI"))
			update_token_links(&token, &prev, &mini);
		token = token->next;
	}
}

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

t_token	*ft_next_token(char *line, int *i)
{
	t_token_data	tok_dat;

	tok_dat.j = 0;
	tok_dat.c = ' ';
	tok_dat.i = i;
	tok_dat.line = line;
	tok_dat.token = malloc(sizeof(t_token));
	if (!(tok_dat.token))
		return (NULL);
	tok_dat.token->str = malloc(ft_next_alloc(line, i));
	if (!(tok_dat.token->str))
		return (NULL);
	process_token_string(&tok_dat);
	tok_dat.token->str[(tok_dat.j)] = '\0';
	return (tok_dat.token);
}

t_token	*ft_get_tokens(char *line)
{
	t_token	*prev;
	t_token	*next;
	int		i;
	int		sep;

	prev = NULL;
	next = NULL;
	i = 0;
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
