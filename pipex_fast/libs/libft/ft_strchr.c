/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:17:54 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:17:56 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strchr() function locates the first occurrence of c (converted to a
char) in the string pointed to by s. 
The terminating null character is considered to be part of the string; 
therefore if c is `\0', the functions locate the terminating `\0'. */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
