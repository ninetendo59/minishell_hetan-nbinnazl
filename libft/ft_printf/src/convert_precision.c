/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:18:54 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 18:53:22 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//fill in zeroes
static char	*alloc_zero(char *cfstr, char *cstr, t_spec *f)
{
	int		i;
	int		j;
	int		len;

	len = (int)ft_strlen(cstr);
	i = 0;
	j = 0;
	if (cstr[0] == '-')
	{
		i++;
		j++;
		len--;
		f->pcs++;
	}
	while (i < f->pcs)
	{
		if (i < f->pcs - len)
			cfstr[i] = '0';
		else
			cfstr[i] = cstr[j++];
		i++;
	}
	return (cfstr);
}

//put numbers
static char	*precision_putnbr(char *cstr, t_spec *f)
{
	char	*cfstr;

	if (cstr[0] == '-')
	{
		cfstr = ft_calloc(sizeof(char), f->pcs + 2);
		if (!cfstr)
			return (NULL);
		cfstr[0] = '-';
	}
	else
	{
		cfstr = ft_calloc(sizeof(char), f->pcs + 1);
		if (!cfstr)
			return (NULL);
	}
	alloc_zero(cfstr, cstr, f);
	return (cfstr);
}

//applying precision for numbers
static char	*precision_num(char *cstr, t_spec *f)
{
	char	*cfstr;

	if (cstr[0] == '0' && f->pcs == 0)
	{
		cfstr = ft_calloc(sizeof(char), f->pcs + 1);
		if (!cfstr)
			return (NULL);
		return (free(cstr), cfstr);
	}
	else if (f->pcs >= (int)ft_strlen(cstr))
	{
		cfstr = precision_putnbr(cstr, f);
		if (!cfstr)
			return (NULL);
		return (free(cstr), cfstr);
	}
	return (cstr);
}

//apply precision for strings
static char	*precision_str(char *cstr, t_spec *f)
{
	char	*cfstr;

	if ((f->dot && f->pcs == 0)
		|| (IS_LINUX
			&& (ft_strncmp(cstr, BLANK_STR, L_BLANK_STR) == 0 && f->pcs < 6)))
		cfstr = ft_calloc(sizeof(char), 1);
	else
		cfstr = ft_substr(cstr, 0, f->pcs);
	if (!cfstr)
		return (NULL);
	return (free(cstr), cfstr);
}

//apply precision when dot is identified
char	*format_flag_dot(char *cstr, t_spec *f)
{
	char	*cfstr;

	if (!f->dot)
		return (cstr);
	if (f->ftype == 's' || f->ftype == 'c')
		cfstr = precision_str(cstr, f);
	else
		cfstr = precision_num(cstr, f);
	if (!cfstr)
		return (NULL);
	return (cfstr);
}
