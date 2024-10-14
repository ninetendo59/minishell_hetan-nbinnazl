/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:24:06 by hetan             #+#    #+#             */
/*   Updated: 2024/10/15 00:09:37 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	refresh_symbol(t_meta *dat)
{
	dat->pipe = 0;
	dat->left = 0;
	dat->d_left = 0;
	dat->right = 0;
	dat->d_right = 0;
}

static void	count_pipe_redir(char **cmd, t_meta **s_data)
{
	t_meta	*data;

	data = *s_data;
	while (*cmd)
	{
		if (ft_strcmp(*cmd, "|"))
			data->pipe++;
		else if (ft_strcmp(*cmd, "<") || ft_strnstr(*cmd, "<", INT_MAX))
			data->left++;
		else if (ft_strcmp(*cmd, "<<") || ft_strnstr(*cmd, "<<", INT_MAX))
			data->d_left++;
		else if (ft_strcmp(*cmd, ">") || ft_strnstr(*cmd, ">", INT_MAX))
			data->right++;
		else if (ft_strcmp(*cmd, ">>") || ft_strnstr(*cmd, ">>", INT_MAX))
			data->d_right++;
	}
}

static void	cmd_fail(int err, char *cmd)
{
	if (err == EACCES)
		printf("MINISHELL: permission denied: %s", cmd);
	else if (err == ENOENT)
		printf("MINISHELL: command not found: %s", cmd);
}

void	shell_cmd(t_meta *data)
{
	char	**split_cmd;

	split_cmd = ft_split(data->cmd, ' ');
	if (!split_cmd)
		return ;
	count_pipe_redir(split_cmd, &data);
	cmd_fail(execve("../shell/builtins", split_cmd, NULL), *split_cmd);
}