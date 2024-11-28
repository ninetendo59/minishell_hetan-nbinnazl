/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:39:21 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 03:00:30 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_token_string(t_token_data *data)
{
	while (data->line[*(data->i)] && (data->line[*(data->i)] != ' '
			|| data->c != ' '))
	{
		if (data->c == ' ' && (data->line[*(data->i)] == '\''
				|| data->line[*(data->i)] == '\"'))
			data->c = data->line[(*(data->i))++];
		else if (data->c != ' ' && data->line[*(data->i)] == data->c)
		{
			data->c = ' ';
			(*(data->i))++;
		}
		else if (data->line[*(data->i)] == '\\' && (*(data->i))++)
			data->token->str[(data->j)++] = data->line[(*(data->i))++];
		else
			data->token->str[(data->j)++] = data->line[(*(data->i))++];
	}
}

void	update_token_links(t_token **token, t_token **prev, t_meta **mini)
{
	while (ft_islast_validarg((*prev)) == 0)
		(*prev) = (*prev)->prev;
	(*token)->prev->next = (*token)->next;
	if ((*token)->next)
		(*token)->next->prev = (*token)->prev;
	(*token)->prev = (*prev);
	if ((*prev))
		(*token)->next = (*token)->next;
	else
		(*token)->next = (*mini)->start;
	if (!(*prev))
		(*prev) = (*token);
	(*prev)->next->prev = (*token);
	if (!((*mini)->start->prev))
		(*prev)->next = (*token);
	if ((*mini)->start->prev)
		(*mini)->start = (*mini)->start->prev;
}
