/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 03:01:58 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 03:01:59 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	ft_free_token(t_token *start)
{
	t_token	*temp;

	while (start)
	{
		temp = start->next;
		ft_memdel(start->str);
		ft_memdel(start);
		start = temp;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_memdel(tab[i++]);
	if (tab)
		ft_memdel(tab);
}

void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		ft_memdel(env->value);
		ft_memdel(env);
		env = tmp;
	}
}
