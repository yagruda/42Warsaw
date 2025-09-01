/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:22:52 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:22:53 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The calloc() function contiguously allocates enough space for count
objects that are size bytes of memory each and returns a pointer to the
allocated memory. The allocated memory is filled with bytes of value zero.*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*memoire;

	memoire = (void *)malloc(count * size);
	if (memoire == NULL)
		return (NULL);
	ft_bzero(memoire, count * size);
	return (memoire);
}
