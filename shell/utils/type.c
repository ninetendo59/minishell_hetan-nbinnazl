/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 03:02:18 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 03:28:42 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_istype(t_token *token, int type)
{
	return ((token && token->type == type));
}

int	ft_istypes(t_token *token, char *types)
{
	if ((ft_strchr(types, ' ') && ft_istype(token, EMPTY))
		|| (ft_strchr(types, 'X') && ft_istype(token, CMD))
		|| (ft_strchr(types, 'x') && ft_istype(token, ARG))
		|| (ft_strchr(types, 'T') && ft_istype(token, TRUNC))
		|| (ft_strchr(types, 'A') && ft_istype(token, APPEND))
		|| (ft_strchr(types, 'I') && ft_istype(token, INPUT))
		|| (ft_strchr(types, 'P') && ft_istype(token, PIPE))
		|| (ft_strchr(types, 'E') && ft_istype(token, END)))
		return (1);
	return (0);
}

int	ft_has_pipe(t_token *token)
{
	while (token && ft_istype(token, END) == 0)
	{
		if (ft_istype(token, PIPE))
			return (1);
		token = token->next;
	}
	return (0);
}

int	ft_has_type(t_token *token, int type)
{
	while (token)
	{
		if (ft_istype(token, type))
			return (1);
		token = token->next;
	}
	return (0);
}

t_token	*ft_next_type(t_token *token, int type, int jump)
{
	if (token && jump)
		token = token->next;
	while (token && token->type != type)
		token = token->next;
	return (token);
}
