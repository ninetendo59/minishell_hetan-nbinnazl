/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:01:00 by hetan             #+#    #+#             */
/*   Updated: 2023/05/06 17:01:02 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *need, size_t size)
{
	size_t	n;
	size_t	c;
	size_t	len_need;
	char	*new_hay;

	n = 0;
	new_hay = (char *)hays;
	len_need = ft_strlen(need);
	if (len_need == 0 || hays == need)
		return (new_hay);
	while (new_hay[n] != 0 && n < size)
	{
		c = 0;
		while (new_hay[n + c] != 0 && need[c] != 0
			&& new_hay[n + c] == need[c] && n + c < size)
			c++;
		if (c == len_need)
			return (new_hay + n);
		n++;
	}
	return (0);
}
