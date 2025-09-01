/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:18:20 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:26:34 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strlcpy() and strlcat() functions copy and concatenate strings with
the same input parameters and output result as snprintf(3).
The strlcpy() function copies up to dstsize - 1 characters from the string 
src to dst, NUL-terminating the result if dstsize is not 0. */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	x;

	if (dst == NULL || src == NULL)
		return (0);
	x = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}
