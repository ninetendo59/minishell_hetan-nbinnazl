/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:36:33 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:12:11 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//count how many places is required.
int	count_octal_place(size_t nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb != 0)
	{
		nb /= 8;
		count++;
	}
	return (count);
}

//octal conversion to ascii
char	*set_spec_oct(size_t nb)
{
	char	*oct;
	char	*baseoct;
	int		count;

	count = count_octal_place(nb);
	baseoct = "01234567";
	oct = ft_calloc(sizeof(*oct), count + 1);
	if (!oct)
		return (NULL);
	while (count > 0)
	{
		oct[--count] = baseoct[nb & 7];
		nb >>= 3;
	}
	return (oct);
}
