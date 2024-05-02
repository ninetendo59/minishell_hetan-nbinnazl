/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:56:04 by hetan             #+#    #+#             */
/*   Updated: 2023/05/07 20:56:07 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(long long n)
{
	size_t		len;
	long long	num;

	len = 0;
	num = n;
	if (num == 0)
	{
		len = 1;
		return (len);
	}
	if (num < 0)
	{
		num = num * -1;
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*handle_long(char *itoa, long long count, long long n)
{
	int		isneg;

	itoa = (char *)malloc(sizeof(char) * (getlen(n) + 1));
	if (!itoa)
		return (NULL);
	count = getlen(n);
	isneg = 0;
	itoa[count] = '\0';
	if (n < 0)
	{
		n *= -1;
		isneg = 1;
	}
	while (--count)
	{
		itoa[count] = (n % 10) + '0';
		n = n / 10;
	}
	if (!isneg)
		itoa[count] = (n % 10) + '0';
	else
		itoa[count] = '-';
	return (itoa);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	long long	num;

	num = n;
	itoa = 0;
	itoa = handle_long(itoa, getlen(num), num);
	if (!itoa)
		return (NULL);
	return (itoa);
}
