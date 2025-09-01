/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:16:07 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:16:09 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Create a duplicate of the given string using malloc
char	*ft_strdup(const char *src)
{
	unsigned int	size;
	char			*dup;
	char			*temp_ptr;

	if (!src)
		return (NULL);
	size = 0;
	while (src[size])
	{
		size++;
	}
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	temp_ptr = dup;
	while (*src)
	{
		*temp_ptr = *src;
		temp_ptr++;
		src++;
	}
	*temp_ptr = '\0';
	return (dup);
}
/*
int	main(void){
	char *s = "Hello";
	char *ptr = ft_strdup(s);
	printf("output: %s", ptr);
	free(ptr);
	return(0);
}
*/
