/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:00:15 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 19:12:48 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//count how many places
static int	count_uint_len(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

//converts unsigned integer number to ascii
char	*set_spec_uint(unsigned int nb)
{
	char	*ui;
	int		count;

	count = count_uint_len(nb);
	ui = ft_calloc(sizeof(*ui), count + 1);
	if (!ui)
		return (NULL);
	if (nb == 0)
	{
		*ui = '0';
		return (ui);
	}
	while (count > 0)
	{
		ui[--count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ui);
}
