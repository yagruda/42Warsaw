/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:16:38 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:16:39 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr = (const unsigned char *)s1;
	const unsigned char	*s2_ptr = (const unsigned char *)s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
		{
			return (s1_ptr[i] - s2_ptr[i]);
		}
		i++;
	}
	return (0);
}
