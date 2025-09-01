/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:20:39 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:20:44 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "error.h"

# define TRUE 1
# define FALSE 0

char	**ft_get_path(char **envp);
char	*ft_get_cmd_path(char **envp, char *cmd);
void	ft_child1_process(char **argv, char **envp, int *fd);
void	ft_child2_process(char **argv, char **envp, int *fd);
void	ft_error_message(char *str, char *message, int error);
void	ft_run_command(char *cmd1, char **envp);
void	ft_close_fd(int *fd);

#endif