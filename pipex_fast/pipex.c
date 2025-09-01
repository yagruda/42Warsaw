/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:13:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:13:24 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	status;
	int	exit_code;

	if (argc != 5)
		error_exit("Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile",
			1);
	if (pipe(pipefd) < 0)
		error_exit("pipe", 1);
	fork_processes(argv, envp, pipefd, &status);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else
		exit_code = 1;
	return (exit_code);
}
