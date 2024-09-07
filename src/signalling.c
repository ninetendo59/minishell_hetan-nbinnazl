/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:49:05 by hetan             #+#    #+#             */
/*   Updated: 2024/09/08 06:10:25 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_sig(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	return ;
}

void	ctrl_c(int sig)
{
	(void)sig;
}

void	ft_init_signal(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	g_sig.exit_stat = 0;
}