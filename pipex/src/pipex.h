/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:52:57 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/29 16:02:54 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include "../libftprintf/libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

void	exit_handler(int exit_code);
int		open_file(char *filename, int mode);
void	ft_free_tab(char **array);
char	*my_getenv(char *varname, char **envp);
char	*get_path(char *cmd_name, char **envp);

void	execute_cmd(char *command, char **envp);
void	child_process(char **argv, int *pipe_fd, char **envp);
void	parent_process(char **argv, int *pipe_fd, char **envp);

#endif