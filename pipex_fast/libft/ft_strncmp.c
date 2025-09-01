/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:15:47 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:15:49 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// compare two strings up to n characters
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
int	main(void){
	char *str1 = "hello1";
	char *str2 = "h2llo2";
	int res = ft_strncmp(str1, str2, 2);
	printf("\n%d\n", res);
	return(0);
}
*/
