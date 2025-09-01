/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:20:31 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:28:27 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_run_command(char *cmd1, char **envp)
{
	char	**cmd_parts;
	char	*path;
	int		i;

	path = NULL;
	cmd_parts = ft_split(cmd1, ' ');
	path = ft_get_cmd_path(envp, cmd_parts[0]);
	if (!path || !cmd_parts)
	{
		i = -1;
		while (cmd_parts[++i])
			free (cmd_parts[i]);
		free (cmd_parts);
		ft_error_message(E_CMD, "Errno", 1);
	}
	execve(path, cmd_parts, envp);
	ft_error_message(E_EXECVE, "Errno", 1);
}

void	ft_child1_process(char **argv, char **envp, int *fd)
{
	int		file1;

	file1 = open(argv[1], O_RDONLY, 0644);
	if (file1 == -1)
		ft_error_message(E_OPENI, "Errno", 0);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(file1);
	ft_close_fd(fd);
	ft_run_command(argv[2], envp);
}

void	ft_child2_process(char **argv, char **envp, int *fd)
{
	int		file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		ft_error_message(E_OPENO, "Errno", 1);
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(file2);
	ft_close_fd(fd);
	ft_run_command(argv[3], envp);
}
