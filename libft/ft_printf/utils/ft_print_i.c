/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:56:58 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 18:40:49 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//convert int as ascii
char	*set_spec_num(int nb)
{
	char	*str;

	str = ft_itoa(nb);
	if (!str)
		return (NULL);
	return (str);
}
