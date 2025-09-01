/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:13:53 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:14:02 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	open_file(const char *path, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		if (mode == 0)
			perror("Error opening infile");
		else
			perror("Error opening outfile");
	}
	return (fd);
}
