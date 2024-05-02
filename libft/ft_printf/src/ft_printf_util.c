/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:08:54 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:11:02 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//prints characters and return how much characters has been printed with len
static int	print_format_char(char *cstr, int len)
{
	int		n;

	n = 0;
	if (len == 0)
		len = 1;
	while (n < len)
		write(1, &cstr[n++], 1);
	return (n);
}

//basically prints nothing if null character
static int	print_blank(char *cast, t_spec *f)
{
	int		n;

	n = 0;
	if (cast[0] == 0 && f->length)
		n = print_format_char(" ", 1);
	else if (cast[0] == 0 && f->dot && f->pcs < 0)
		n = print_format_char(BLANK_STR, L_BLANK_STR);
	else if (ft_strlen(cast) > 0 && f->length > 0)
	{
		while (n++ < f->length)
			ft_putchar_fd(' ', 1);
		n--;
	}
	return (n);
}

/*
	this is to print as string.

	1. when the precision is identified as 0 and it's a string,
	   then it will print as blank.
	2. when the length is more than zero, then it will proceed to
	   print the strings
	3. when the length input is not zero, then it will print based
	   on the length provided in the specifier
	4. or else, it will print nothing
*/
static int	print_format_str(char *cast, t_spec *f)
{
	int		n;

	if ((f->ftype == 's' && f->dot && f->pcs == 0) || (cast[0] == 0))
		return (print_blank(cast, f));
	n = ft_strlen(cast);
	if (f->length > 0 && n == 0)
		n = print_format_char(cast, f->length);
	else
		ft_putstr_fd(cast, 1);
	return (n);
}

/*
	int	apply_format(va_list args, t_spec *f)

	applying obtain flags and specifiers and prints out
*/
int	apply_format(va_list args, t_spec *f)
{
	char	*cast;
	int		n;

	cast = set_specifier(args, f);
	cast = format_flag_num(cast, f);
	cast = format_flag_dot(cast, f);
	cast = format_flag_indent(cast, f);
	if (f->ftype == 'c')
		n = print_format_char(cast, f->length);
	else
		n = print_format_str(cast, f);
	free(cast);
	return (n);
}
