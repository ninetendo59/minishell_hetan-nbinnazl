/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:08:44 by hetan             #+#    #+#             */
/*   Updated: 2023/05/04 21:08:52 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *name, int c, size_t size)
{
	size_t			n;
	unsigned char	*uname;

	n = 0;
	uname = (unsigned char *)name;
	while (n < size)
	{
		uname[n] = c;
		n++;
	}
	return (uname);
}
