#include "minishell.h"

int	ft_istype(t_token *token, int type)
{
	return (token && token->type == type);
}

int	ft_istypes(t_token *token, char *types)
{
	if (ft_strchr(types, ' ') && ft_istype(token, EMPTY))
		return (1);
	else if (ft_strchr(types, 'X') && ft_istype(token, CMD))
		return (1);
	else if (ft_strchr(types, 'x') && ft_istype(token, ARG))
		return (1);
	else if (ft_strchr(types, 'T') && ft_istype(token, TRUNC))
		return (1);
	else if (ft_strchr(types, 'A') && ft_istype(token, APPEND))
		return (1);
	else if (ft_strchr(types, 'I') && ft_istype(token, INPUT))
		return (1);
	else if (ft_strchr(types, 'P') && ft_istype(token, PIPE))
		return (1);
	else if (ft_strchr(types, 'E') && ft_istype(token, END))
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
