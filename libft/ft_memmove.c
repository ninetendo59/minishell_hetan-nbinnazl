/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:55:36 by hetan             #+#    #+#             */
/*   Updated: 2023/05/04 21:55:38 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*mdest;
	const unsigned char	*msrc;

	mdest = (unsigned char *)dest;
	msrc = (const unsigned char *)src;
	if ((!dest && !src) || (dest == src))
		return (dest);
	if (dest == src)
		return (dest);
	if (msrc < mdest)
	{
		while (num--)
			*(mdest + num) = *(msrc + num);
		return (dest);
	}
	while (num--)
		*mdest++ = *msrc++;
	return (dest);
}
