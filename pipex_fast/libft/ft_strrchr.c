/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:15:40 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:15:41 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// find the last occurrence of the character c in the string str
char	*ft_strrchr(const char *str, int c)
{
	char	*result;

	result = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			result = (char *)str;
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (result);
}
/*
int	main(void){
	char *str = "Testingsussy";
	char *ptr = ft_strrchr(str, 's');
	printf("%s", ptr);
	return(0);
}
*/
