/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:49:05 by hetan             #+#    #+#             */
/*   Updated: 2024/04/01 04:52:35 by hetan            ###   ########.fr       */
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
	write(1, "\n", 1);
	curr_dir();
}

void	ft_init_signal(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	g_sig.exit_stat = 0;
}