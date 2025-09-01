/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:23:02 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:23:03 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The isalpha() function checks if the passed character is alphabetic. */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
