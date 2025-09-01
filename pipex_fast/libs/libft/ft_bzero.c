/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:22:06 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:22:07 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The bzero() function copies n bytes (b), 
each with a value of zero, into string s */

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (n > 0)
	{
		((char *)s)[i] = 0;
		i++;
		n--;
	}
}
