/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:42:53 by hetan             #+#    #+#             */
/*   Updated: 2023/05/03 00:42:55 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			num;
	unsigned char	*str_null;

	num = 0;
	str_null = (unsigned char *)str;
	while (num < n)
	{
		str_null[num] = 0;
		num++;
	}
}
