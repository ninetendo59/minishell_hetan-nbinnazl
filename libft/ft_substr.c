/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 03:35:28 by hetan             #+#    #+#             */
/*   Updated: 2023/05/07 03:35:31 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	lens;
	char	*sub;

	if (start >= ft_strlen(s))
		len = 0;
	else
	{
		s += start;
		lens = ft_strlen(s);
		if (len > lens)
			len = lens;
	}
	sub = malloc(sizeof(*sub) * (len + 1));
	if (sub)
	{
		if (len > 0)
			ft_strlcpy(sub, s, len + 1);
		else
			sub[0] = '\0';
	}
	return (sub);
}
