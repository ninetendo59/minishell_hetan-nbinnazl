/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:09:10 by hetan             #+#    #+#             */
/*   Updated: 2023/11/03 18:48:01 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	this is extend version of my library
*/

/*
	not really a real orignal realloc function but to move to new memory
*/
void	*my_realloc(void *ptr, size_t size)
{
	void	*new;
	size_t	msize;

	msize = my_memsize(ptr);
	if (size <= msize)
		return (ptr);
	new = malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	if (!ptr)
		return (new);
	ft_memcpy(new, ptr, msize);
	free(ptr);
	ptr = NULL;
	return (new);
}

//calculate total memory size which based on strings
size_t	my_memsize(void *ptr)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char *) ptr;
	while (*str++)
		n++;
	return (n);
}

//conversion of string to uppercase
char	*my_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

//calculate length of printed characters include when string is nothing as 1
int	my_printlen(char *str)
{
	int		n;

	n = ft_strlen(str);
	if (n == 0)
		return (1);
	else
		return (n);
}
