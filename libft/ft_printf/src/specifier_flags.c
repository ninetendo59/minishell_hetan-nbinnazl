/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:06:21 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:11:28 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//applying the spec cspduixXo% based on their purpose
char	*set_specifier(va_list args, t_spec *f)
{
	char	*str;

	if (f->ftype == 'c')
		str = set_spec_char(va_arg(args, int));
	else if (f->ftype == 's')
		str = set_spec_str(va_arg(args, char *));
	else if (f->ftype == 'p')
		str = set_spec_ptr((unsigned long long) va_arg(args, void *));
	else if (f->ftype == 'i' || f->ftype == 'd')
		str = set_spec_num(va_arg(args, int));
	else if (f->ftype == 'u')
		str = set_spec_uint(va_arg(args, int));
	else if (f->ftype == 'x' || f->ftype == 'X')
		str = set_spec_hex(va_arg(args, unsigned int), f->ftype);
	else if (f->ftype == 'o')
		str = set_spec_oct(va_arg(args, unsigned int));
	else if (f->ftype == '%')
		str = set_spec_char('%');
	else
		str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	return (str);
}

//fill flags and spec identified into container as format
int	config_flag(char c, t_spec *f)
{
	if (f->dot && ft_isdigit(c))
		f->pcs = (f->pcs * 10) + (c - '0');
	else if (check_spec(c))
		f->ftype = c;
	else if (c == '-')
		f->minus = 1;
	else if (c == '+')
		f->plus = 1;
	else if (c == ' ')
		f->blank += 1;
	else if (c == '0' && f->length == 0)
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == '.')
		f->dot = 1;
	else if (ft_isdigit(c))
		f->length = (f->length * 10) + (c - '0');
	else
		return (0);
	return (1);
}
