/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:06:19 by hetan             #+#    #+#             */
/*   Updated: 2023/05/02 23:06:24 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t			n;
	int				res;
	int				sign;

	n = 0;
	res = 0;
	sign = 1;
	while (str[n] && (str[n] == 32 || (str[n] >= 9 && str[n] <= 13)))
		n++;
	if (str[n] == '-')
	{
		sign *= -1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	if (!ft_isdigit(str[n]))
		return (0);
	while (ft_isdigit(str[n]))
	{
		res = (res * 10) + (str[n] - '0');
		n++;
	}
	return (res * sign);
}
