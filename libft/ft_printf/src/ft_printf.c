/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:06:26 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:10:41 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PRINTF

	Introduction: just a printf

	handling mandatory (%):
	1. characters
	2. strings
	3. pointer address
	4. decimal (base 10)
	5. integer
	6. unsigned integer
	7. lower case hexadecimal
	8. upper case hexadecimal
	9. prints percent sign
	10. octal (extra)

	handling bonus flags
	1. hash - shows 0x on %x
	2. minus - right indent
	3. zero - fill zeroes infront
	4. dot - precision
	5. number - right indent
	6. space - fill space when positive number
	7. plus - displays +/- sign on base 10 numbers
*/

/*
	static char	*get_format(const char *format, t_spec *f)

	this function is to extracts the specifiers.

	set_format --> to construct the string
	clear_format --> resets the container
	config_flag --> to identify the flags and specs.
*/
static char	*get_format(const char *format, t_spec *f)
{
	int		n;
	char	*str;

	str = set_format(NULL, '%', 0);
	if (!str)
		return (NULL);
	n = 1;
	clear_format(f);
	while (format[n])
	{
		if (!config_flag(format[n], f))
		{
			free(str);
			return (NULL);
		}
		str = set_format(str, format[n], n);
		if (!format)
			return (NULL);
		if (f->ftype)
			return (str);
		n++;
	}
	free(str);
	return (NULL);
}

/*
	static int	browse_format(const char *format, va_list args)
	
	this function browses each of the characters to find %
	
	1. get_format, which to identify what kind of specifiers has been
	   declared and store it into *str
	2. second, when everything is identified, it will apply the format
	   with apply_format().
	3. The apply_format() will identify, then prints out the applied
	   format.
	4. once complete print the first one, it will move the ptr address
	   of the *format based on how much characters has been identified
	   as specifier include the %.
	5. after complete usage of *str which obtained from get_format,
	   will be free.
	6. if not found %, then it will print the characters accordingly.
*/
static int	browse_format(const char *format, va_list args)
{
	char		*str;
	int			count;
	t_spec		f;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			str = get_format(format, &f);
			if (str)
			{
				count += apply_format(args, &f);
				format += ft_strlen(str);
				free(str);
			}
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
			format++;
		}
	}
	return (count);
}

//main function. returns NULL if function called as ft_printf();
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (0);
	va_start(args, format);
	count = browse_format(format, args);
	va_end(args);
	return (count);
}
