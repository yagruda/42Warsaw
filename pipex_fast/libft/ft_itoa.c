/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:16:44 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:16:45 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// in case of 0 we should ++
// in case of negative number we should ++ for the sign
static int	numlen(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
	{
		length++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	long	num;
	char	*result;

	num = n;
	length = numlen(num);
	result = (char *)ft_calloc(sizeof(char), length + 1);
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	while (--length >= 0 && result[length] != '-')
	{
		result[length] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}
