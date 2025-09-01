/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:13:28 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:13:30 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	error_exit(const char *msg, int exit_code);
char	*get_cmd_path(char *cmd, char **envp);
void	free_2d(char **str);
int		open_file(const char *path, int mode);
void	fork_processes(char **argv, char **envp, int pipefd[2], int *status);

#endif
