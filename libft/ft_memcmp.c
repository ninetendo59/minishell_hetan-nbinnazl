/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:14:54 by hetan             #+#    #+#             */
/*   Updated: 2023/05/03 22:14:57 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t num)
{
	size_t				n;
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	n = 0;
	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	while (n < num)
	{
		if (cs1[n] != cs2[n])
			return (cs1[n] - cs2[n]);
		n++;
	}
	return (0);
}
