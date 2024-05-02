/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:32:05 by hetan             #+#    #+#             */
/*   Updated: 2023/04/29 23:48:28 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	if (!dest || !src)
		return (0);
	n = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (n < size - 1 && src[n] != '\0')
	{
		*(dest + n) = *(src + n);
		n++;
	}
	if (n < size)
		*(dest + n) = '\0';
	while (*(src + n) != '\0')
		n++;
	return (n);
}
