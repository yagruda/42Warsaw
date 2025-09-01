/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:24:57 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:24:58 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The putchar_fd() function outputs the character 'c' to 
the given file descriptor. */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
