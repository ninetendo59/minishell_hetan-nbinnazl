/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:08:36 by hetan             #+#    #+#             */
/*   Updated: 2023/05/06 18:08:38 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char		ch;
	const char	*last;

	last = NULL;
	ch = (char)c;
	while (*str != '\0')
	{
		if (*str == ch)
			last = str;
		str++;
	}
	if (*str == c)
		last = str;
	return ((char *)last);
}
