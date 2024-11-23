#include "minishell.h"

int	ft_istype(t_token *token, int type)
{
	return (token && token->type == type);
}

int	ft_istypes(t_token *token, char *types)
{
	if (ft_gnlstrchr(types, ' ') && ft_istype(token, EMPTY))
		return (1);
	else if (ft_gnlstrchr(types, 'X') && ft_istype(token, CMD))
		return (1);
	else if (ft_gnlstrchr(types, 'x') && ft_istype(token, ARG))
		return (1);
	else if (ft_gnlstrchr(types, 'T') && ft_istype(token, TRUNC))
		return (1);
	else if (ft_gnlstrchr(types, 'A') && ft_istype(token, APPEND))
		return (1);
	else if (ft_gnlstrchr(types, 'I') && ft_istype(token, INPUT))
		return (1);
	else if (ft_gnlstrchr(types, 'P') && ft_istype(token, PIPE))
		return (1);
	else if (ft_gnlstrchr(types, 'E') && ft_istype(token, END))
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
