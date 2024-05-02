/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:18:57 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 01:30:54 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	char	*sstr;

	if (str == NULL)
		return (0);
	sstr = (char *)str;
	while (*sstr != '\0')
		sstr++;
	return ((size_t)(sstr - str));
}
