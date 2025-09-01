/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:18:13 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:18:13 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strlcat() function copy and concatenate strings with
the same input parameters and output result as snprintf(3).
It appends string src to the end of dst.  It will append at most
dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
dstsize is 0 or the original dst string was longer than dstsize (in practice 
this should not happen as it means that either dstsize is incorrect
or that dst is not a proper string). */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = dlen;
	if (dstsize == 0 || dstsize <= dlen)
		return (slen + dstsize);
	while (src[i] != '\0' && i < dstsize - dlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
