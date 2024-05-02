/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:20:58 by hetan             #+#    #+#             */
/*   Updated: 2023/05/20 15:10:24 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	nulcek;
	void	*mem;

	nulcek = count * size;
	if (nulcek != 0 && nulcek / size != count)
		return (NULL);
	mem = malloc(nulcek);
	if (mem != NULL)
		ft_bzero(mem, nulcek);
	return (mem);
}
