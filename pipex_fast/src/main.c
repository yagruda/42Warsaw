/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:20:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:28:36 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error_message(E_PIPE, "Errno", 1);
		pid = fork();
		if (pid == -1)
			ft_error_message(E_FORK, "Errno", 1);
		else if (pid == 0)
			ft_child1_process(argv, envp, fd);
		else
		{
			wait(NULL);
			pid = fork();
			if (pid == 0)
				ft_child2_process(argv, envp, fd);
		}
		ft_close_fd(fd);
	}
	else if (argc != 5 || envp[0][0] == '\n')
		ft_error_message(E_ARG, "Errno", 1);
	return (0);
}
