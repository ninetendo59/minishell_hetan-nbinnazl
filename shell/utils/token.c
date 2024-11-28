/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:24:43 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 03:02:15 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else
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
	{
		token = token->next;
		if (token && token->type == CMD && token->prev->type < END)
			token = token->next;
		else if (token && token->type == CMD && token->prev == NULL)
			continue ;
	}
	return (token);
}
