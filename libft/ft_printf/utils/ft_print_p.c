/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:00:04 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 18:42:20 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//displays the address
char	*set_spec_ptr(uintptr_t ptr)
{
	char	*hex;
	char	*str;

	if (!ptr)
	{
		str = ft_calloc(sizeof(*str), L_NULL_PTR + 1);
		if (!str)
			return (NULL);
		str = ft_memcpy(str, NULL_PTR, L_NULL_PTR);
		return (str);
	}
	hex = uitoh(ptr);
	if (!hex)
		return (NULL);
	str = ft_strjoin("0x", hex);
	if (!str)
		return (free(hex), NULL);
	free(hex);
	return (str);
}
