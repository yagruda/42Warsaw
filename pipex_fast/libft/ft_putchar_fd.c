/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:16:26 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:16:27 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// writes the character c to the file descriptor fd
/*
0 for standard input (stdin)
1 for standard output (stdout)
2 for standard error (stderr)
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
