/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:47:25 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 01:47:26 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_b_env(t_env *env)
{
	while (env)
	{
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
	return (0);
}
