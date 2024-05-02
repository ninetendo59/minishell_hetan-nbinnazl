/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 05:45:38 by hetan             #+#    #+#             */
/*   Updated: 2023/12/18 00:09:43 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <stdlib.h>
# include "libft.h"

# ifdef __linux__
#  define IS_LINUX 1
#  define OS "LINUX"
#  define BLANK_STR "(null)"
#  define L_BLANK_STR 6
#  define NULL_PTR "(nil)"
#  define L_NULL_PTR 5
# else
#  define IS_LINUX 0
#  define OS "MAC"
#  define BLANK_STR "(null)"
#  define L_BLANK_STR 6
#  define NULL_PTR "0x0"
#  define L_NULL_PTR 3
# endif

# define F_TYPE "cspdiuxXo%"

//for bonus part + mandatory
//purpose is to read the specifier
typedef struct s_spec
{
	int		minus;
	int		plus;
	int		blank;
	int		zero;
	int		hash;
	int		dot;
	int		length;
	int		pcs;
	char	ftype;
}	t_spec;

//extra function
void	*my_realloc(void *ptr, size_t size);
size_t	my_memsize(void *ptr);
char	*my_strtoupper(char *str);
char	*uitoh(size_t nb);
int		my_printlen(char *str);

//ft_printf main function
//purpose: print format as output
int		ft_printf(const char *str, ...);

//cspdiuxX utilities
int		check_spec(char c);
char	*set_specifier(va_list args, t_spec *f);
char	*set_spec_char(char c);
char	*set_spec_num(int nb);
char	*set_spec_str(char *s);
char	*set_spec_ptr(uintptr_t ptr);
char	*set_spec_uint(unsigned int nb);
char	*set_spec_hex(unsigned int nb, char c);
char	*set_spec_oct(size_t nb);

//flags utilities
int		config_flag(char c, t_spec *f);
void	clear_format(t_spec *f);
char	*format_flag_num(char	*cstr, t_spec *f);
char	*format_flag_dot(char *cstr, t_spec *f);
char	*format_flag_indent(char	*cstr, t_spec *f);

//print output utilities
char	*set_format(char *fstr, char c, int i);
int		apply_format(va_list args, t_spec *f);

#endif