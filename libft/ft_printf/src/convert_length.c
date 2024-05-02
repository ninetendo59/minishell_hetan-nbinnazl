/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:34:02 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:09:54 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//fill prefixes when zero flag exists, or if provided length is more than var
static int	fill_prefix(char *cfstr, int i, int n, t_spec *f)
{
	while (i < f->length - n)
	{
		if (f->zero && (!f->dot || f->pcs < 0))
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	return (i);
}

//left indent
static char	*align_left(char *cstr, t_spec *f)
{
	char	*cfstr;
	int		i;
	int		plen;

	i = 0;
	plen = my_printlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->length + 1);
	if (!cfstr)
		return (NULL);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (i < f->length)
	{
		if (i < plen && (f->ftype == 's' && *cstr == 0))
			cfstr[i] = ' ';
		else if (i < plen)
			cfstr[i] = cstr[i];
		else
			cfstr[i] = ' ';
		i++;
	}
	free(cstr);
	return (cfstr);
}

//right indent
static char	*align_right(char *cstr, t_spec *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		plen;

	i = 0;
	j = 0;
	cfstr = ft_calloc(sizeof(char), f->length + 1);
	plen = my_printlen(cstr);
	if (!cfstr)
		return (NULL);
	if (cstr[0] == '-' && (f->zero && (!f->dot || f->pcs < 0)))
	{
		cfstr[i++] = cstr[j++];
		f->length++;
	}
	i = fill_prefix(cfstr, i, plen, f);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (j < plen)
		cfstr[i++] = cstr[j++];
	free(cstr);
	return (cfstr);
}

//indentation whether left or right
char	*format_flag_indent(char	*cstr, t_spec *f)
{
	char	*cfstr;

	if (f->length <= (int)ft_strlen(cstr))
		return (cstr);
	if (f->minus)
		cfstr = align_left(cstr, f);
	else
		cfstr = align_right(cstr, f);
	if (!cfstr)
		return (NULL);
	return (cfstr);
}
