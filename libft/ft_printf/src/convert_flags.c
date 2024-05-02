/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:18:55 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:07:11 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//format the plus flag
static char	*format_plus(char *cstr, t_spec *f)
{
	int		nb;
	char	*cfstr;
	char	*pfx;

	if ((f->plus || f->blank) && (f->ftype == 'd' || f->ftype == 'i'))
	{
		nb = ft_atoi(cstr);
		if (nb < 0)
			return (cstr);
		pfx = ft_calloc(sizeof(char), 2);
		if (!pfx)
			return (free(cstr), NULL);
		if (f->plus)
			pfx[0] = '+';
		else
			pfx[0] = ' ';
		cfstr = ft_strjoin(pfx, cstr);
		free(pfx);
		if (!cfstr)
			return (free(cstr), NULL);
		return (free(cstr), cfstr);
	}
	return (cstr);
}

static char	*format_hash(char *cstr, t_spec *f)
{
	char	*cfstr;
	char	*pfx;

	if (f->hash && (f->ftype == 'x' || f->ftype == 'X') && cstr[0] != '0')
	{
		pfx = ft_calloc(sizeof(char), 3);
		if (!pfx)
			return (free(cstr), NULL);
		pfx[0] = '0';
		pfx[1] = f->ftype;
		cfstr = ft_strjoin(pfx, cstr);
		free(pfx);
		if (!cfstr)
			return (free(cstr), NULL);
		return (free(cstr), cfstr);
	}
	return (cstr);
}

//handling numbers that is formattable by hash and plus
char	*format_flag_num(char *cstr, t_spec *f)
{
	cstr = format_plus(cstr, f);
	if (!cstr)
		return (NULL);
	cstr = format_hash(cstr, f);
	if (!cstr)
		return (NULL);
	return (cstr);
}
