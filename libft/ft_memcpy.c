/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:40:15 by hetan             #+#    #+#             */
/*   Updated: 2023/05/02 21:40:19 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		c;
	char		*destv;
	const char	*srcv;

	c = 0;
	destv = (char *)dest;
	srcv = (const char *)src;
	if (!dest && !src)
		return (dest);
	while (c < n)
	{
		destv[c] = srcv[c];
		c++;
	}
	return (dest);
}
