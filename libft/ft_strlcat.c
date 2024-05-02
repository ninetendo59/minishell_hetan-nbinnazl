/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:04:53 by hetan             #+#    #+#             */
/*   Updated: 2023/04/30 00:18:37 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	len_dest;
	size_t	len_src;

	n = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if ((!size && !dest) || len_dest >= size)
		return (len_src + size);
	while (src[n] && n < (size - len_dest - 1))
	{
		dest[len_dest + n] = src[n];
		n++;
	}
	dest[len_dest + n] = 0;
	return (len_dest + len_src);
}
