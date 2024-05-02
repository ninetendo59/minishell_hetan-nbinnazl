/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:32:15 by hetan             #+#    #+#             */
/*   Updated: 2023/05/07 18:32:16 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	in;
	size_t	out;
	size_t	len;
	char	*trim;

	in = 0;
	out = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(""));
	while (s1[in] && ft_strchr(set, s1[in]))
		in++;
	while (out > in && ft_strchr(set, s1[out - 1]))
		out--;
	len = out - in;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + in, len +1);
	return (trim);
}
