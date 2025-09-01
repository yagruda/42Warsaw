/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:16:30 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:16:31 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// s = block to fill
// c = the value to set
// size = the number of bytes to set
void	*ft_memset(void *s, int c, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (size--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}
