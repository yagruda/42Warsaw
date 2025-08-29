/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:52:59 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/29 16:02:55 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void	execute_cmd(char *command, char **envp)
{
    char	**cmd_split;
    char	*cmd_path;

    cmd_split = ft_split(command, ' ');
    cmd_path = get_path(cmd_split[0], envp);
    if (execve(cmd_path, cmd_split, envp) == -1)
    {
        ft_putstr_fd("pipex: command not found: ", 2);
        ft_putendl_fd(cmd_split[0], 2);
        ft_free_tab(cmd_split);
        exit(0);
    }
}

void	child_process(char **argv, int *pipe_fd, char **envp)
{
    int		infile_fd;

    infile_fd = open_file(argv[1], 0);
    dup2(infile_fd, 0);
    dup2(pipe_fd[1], 1);
    close(pipe_fd[0]);
    execute_cmd(argv[2], envp);
}

void	parent_process(char **argv, int *pipe_fd, char **envp)
{
    int		outfile_fd;

    outfile_fd = open_file(argv[4], 1);
    dup2(outfile_fd, 1);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[1]);
    execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
    int		pipe_fd[2];
    pid_t	child_pid;

    if (argc != 5)
        exit_handler(1);
    if (pipe(pipe_fd) == -1)
        exit(-1);
    child_pid = fork();
    if (child_pid == -1)
        exit(-1);
    if (!child_pid)
        child_process(argv, pipe_fd, envp);
    parent_process(argv, pipe_fd, envp);
}
