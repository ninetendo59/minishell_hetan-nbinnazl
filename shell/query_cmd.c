/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:02:24 by hetan             #+#    #+#             */
/*   Updated: 2024/04/01 21:37:55 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(void)
{
}

void	cd(void)
{
}

void	pwd(void)
{
}

void	exp(void)
{
}

void	uns(void)
{
	
}

t_command	g_commands[] = {
{"echo", echo},
{"cd", cd},
{"pwd", pwd},
{"export", exp},
{"unset", uns},
{"pwd", pwd},
};

t_command	*find_command(const char *name)
{
	int	i;

	i = 0;
	while (i < (int)(sizeof(g_commands) / sizeof(t_command)))
	{
		if (strcmp(g_commands[i].name, name) == 0)
			return (&g_commands[i]);
		i++;
	}
	return (NULL);
}
