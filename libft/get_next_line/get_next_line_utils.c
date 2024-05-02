/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:17:24 by hetan             #+#    #+#             */
/*   Updated: 2024/01/03 02:58:36 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//taken from libft

//taken from libft
char	*gnl_strchr(char *str, int c)
{
	char	ch;

	ch = (char)c;
	while (*str)
	{
		if (*str == ch)
			return (str--);
		str++;
	}
	if (*str == ch)
		return (str--);
	return (0);
}

//taken from libft, for substr purpose
size_t	gnl_strlcpy(char *dest, char *src, size_t size)
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

char	*gnl_substr(char *s, unsigned int start, size_t len)
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
			gnl_strlcpy(sub, s, len + 1);
		else
			*sub = '\0';
	}
	return (sub);
}

// current != ori, modded to suit ft_get_line as ori >25l if free mem
char	*gnl_strjoin(char *dest, char *src)
{
	char	*join;
	char	*temp;
	char	*dtmp;

	if (!dest)
	{
		dest = (char *)malloc(sizeof(*dest) * 1);
		*dest = '\0';
	}
	if (!dest || !src)
		return (NULL);
	join = malloc(sizeof(*join) * (ft_strlen(dest) + ft_strlen(src) + 1));
	if (join == NULL)
		return (NULL);
	temp = join;
	dtmp = dest;
	if (dtmp)
		while (*dtmp != '\0')
			*(temp++) = *(dtmp++);
	while (*src != '\0')
		*(temp++) = *(src++);
	*temp = '\0';
	free(dest);
	return (join);
}
