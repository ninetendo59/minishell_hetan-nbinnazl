/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:00:12 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:12:22 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//identify whether is it upper case as boolean
static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

//calculate how many possible places to construct hex
static int	hex_length(size_t nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

//convert number to hex as in ascii
char	*uitoh(size_t nb)
{
	char	*hex;
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = hex_length(nb);
	hex = ft_calloc(sizeof(*hex), count + 1);
	if (!hex)
		return (NULL);
	if (nb == 0)
	{
		hex[0] = '0';
		return (hex);
	}
	while (count > 0)
	{
		hex[--count] = base[nb & 0XF];
		nb >>= 4;
	}
	return (hex);
}

//identify whether upper case or lower case of %x specifier
char	*set_spec_hex(unsigned int nb, char c)
{
	char	*hex;

	hex = uitoh(nb);
	if (!hex)
		return (NULL);
	if (ft_isupper(c))
		hex = my_strtoupper(hex);
	return (hex);
}
