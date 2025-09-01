/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:24:33 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:24:34 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memchr() function locates the first occurrence of c (converted to an
unsigned char) in string s. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
