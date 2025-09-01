/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:24:52 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:24:53 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memset() function writes len bytes of value c (converted to an
unsigned char) to the string b. */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (b == NULL)
		return (0);
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}
