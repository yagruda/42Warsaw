/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:18:28 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:18:30 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strmapi() function applies the function ’f’ to each character of the 
string ’s’, and passing its index as first argument to create 
a new string (with malloc(3)) resulting from successive applications of ’f’. 
It returns the result of the applications of f on s. */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*memoire;

	i = 0;
	memoire = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (memoire == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		memoire[i] = f(i, s[i]);
		i++;
	}
	return (memoire);
}
