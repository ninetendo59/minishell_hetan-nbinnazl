/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:49:05 by hetan             #+#    #+#             */
/*   Updated: 2024/11/29 02:16:33 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sig_int(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		write(1, "\n", 1);
		write(1, "\033[0;31m🔴 ", ft_strlen("\033[0;31m🔴"));
	}
	else
	{
		ft_putstr_fd("\n", 2);
		g_sig.exit_stat = 130;
	}
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
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

int	handle_signal_and_return(int ret)
{
	if (g_sig.sigint == 1 || g_sig.sigquit == 1)
		return (g_sig.exit_stat);
	if (ret == 32256 || ret == 32512)
		ret = ret / 256;
	else
		ret = !!ret;
	return (ret);
}
