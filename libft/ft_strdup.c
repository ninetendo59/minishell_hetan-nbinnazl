/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:38:47 by hetan             #+#    #+#             */
/*   Updated: 2023/04/30 00:39:36 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*str2;

	len = ft_strlen(str) + 1;
	str2 = (char *)malloc(sizeof(*str2) * len);
	if (str2 == NULL)
		return (NULL);
	str2 = ft_memcpy (str2, str, len);
	return (str2);
}
