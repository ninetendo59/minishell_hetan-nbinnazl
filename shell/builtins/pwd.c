/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:02:21 by hetan             #+#    #+#             */
/*   Updated: 2024/04/01 05:05:34 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_b_pwd(void)
{
	char	*cwd;

	cwd = malloc(sizeof(*cwd) * (BUFFER_SIZE + 1));
	if (!cwd)
		return (free(cwd), 1);
	if (getcwd(cwd, BUFFER_SIZE + 1) != NULL)
	{
		ft_putendl_fd(cwd, 1);
		return (free(cwd), 0);
	}
	else
	{
		perror("getcwd() error");
		return (free(cwd), 1);
	}
}
