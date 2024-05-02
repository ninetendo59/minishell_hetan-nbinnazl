/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:46:29 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 18:39:00 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//identifying cspdiuxXo%
int	check_spec(char c)
{
	char	*spec;

	spec = F_TYPE;
	while (*spec)
		if (*spec++ == c)
			return (1);
	return (0);
}

//clear container
void	clear_format(t_spec *f)
{
	f->minus = 0;
	f->plus = 0;
	f->blank = 0;
	f->zero = 0;
	f->hash = 0;
	f->dot = 0;
	f->length = 0;
	f->pcs = 0;
	f->ftype = 0;
}

//construction of string
char	*set_format(char *fstr, char c, int i)
{
	if (!fstr)
		fstr = ft_calloc(sizeof(char), i + 2);
	else
		fstr = my_realloc(fstr, i + 2);
	if (!fstr)
		return (NULL);
	fstr[i] = c;
	return (fstr);
}
