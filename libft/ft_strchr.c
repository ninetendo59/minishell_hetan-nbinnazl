/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:42:28 by hetan             #+#    #+#             */
/*   Updated: 2023/05/20 14:59:45 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = (char) c;
	while (*str)
	{
		if (*str == ch)
			return ((char *)str--);
		str++;
	}
	if (*str == ch)
		return ((char *)str--);
	return (0);
}
