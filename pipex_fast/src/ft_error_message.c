/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:20:09 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:20:10 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_message(char *str, char *message, int error)
{
	if (!str)
		perror("Error with pipex");
	else
	{
		ft_putstr_fd(str, 2);
		perror(message);
	}
	exit(error);
}
