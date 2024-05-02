/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:51:42 by hetan             #+#    #+#             */
/*   Updated: 2023/05/06 20:51:44 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t				n;
	const unsigned char	*cstr;

	n = 0;
	cstr = (const unsigned char *)str;
	while (n < size)
	{
		if (*cstr == (unsigned char)c)
			return ((void *)cstr);
		cstr++;
		n++;
	}
	return (NULL);
}
