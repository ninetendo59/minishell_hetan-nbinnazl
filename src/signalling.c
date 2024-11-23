/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:49:05 by hetan             #+#    #+#             */
/*   Updated: 2024/09/08 14:11:50 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	check_sig(void)
// {
// 	signal(SIGINT, ctrl_c);
// 	signal(SIGQUIT, SIG_IGN);
// 	return ;
// }

// void	ctrl_c(int sig)
// {
// 	(void)sig;
// 	write(1, "\n", 1);
// 	curr_dir();
// }

void	ft_sig_int(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\b\b  \n\033[0;36m\033[1m🔴 minishell ▸ \033[0m", 2);
		g_sig.exit_stat = 1;
	}
	else
	{
		ft_putstr_fd("\n", 2);
		g_sig.exit_stat = 130;
	}
	g_sig.sigint = 1;
}

void	ft_sig_quit(int code)
{
	char	*nbr;

	nbr = ft_itoa(code);
	if (g_sig.pid != 0)
	{
		ft_putstr_fd("Quit: ", 2);
		ft_putendl_fd(nbr, 2);
		g_sig.exit_stat = 131;
		g_sig.sigquit = 1;
	}
	else
		ft_putstr_fd("\b\b  \b\b", 2);
	ft_memdel(nbr);
}

void	ft_init_signal(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	g_sig.exit_stat = 0;
}
