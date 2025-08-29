/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:52:54 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/29 16:04:04 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void	exit_handler(int exit_code)
{
    if (exit_code == 1)
        ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
    exit(0);
}

int	open_file(char *filename, int mode)
{
    int	fd;

    if (mode == 0)
        fd = open(filename, O_RDONLY, 0777);
    if (mode == 1)
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1)
        exit(0);
    return (fd);
}

void	ft_free_tab(char **array)
{
    size_t	idx;

    idx = 0;
    while (array[idx])
    {
        free(array[idx]);
        idx++;
    }
    free(array);
}

char	*my_getenv(char *varname, char **envp)
{
    int		i;
    int		j;
    char	*substr;

    i = 0;
    while (envp[i])
    {
        j = 0;
        while (envp[i][j] && envp[i][j] != '=')
            j++;
        substr = ft_substr(envp[i], 0, j);
        if (ft_strcmp(substr, varname) == 0)
        {
            free(substr);
            return (envp[i] + j + 1);
        }
        free(substr);
        i++;
    }
    return (NULL);
}

char	*get_path(char *cmd_name, char **envp)
{
    int		i;
    char	*exec_path;
    char	**paths;
    char	*path_prefix;
    char	**cmd_split;

    i = -1;
    paths = ft_split(my_getenv("PATH", envp), ':');
    cmd_split = ft_split(cmd_name, ' ');
    while (paths[++i])
    {
        path_prefix = ft_strjoin(paths[i], "/");
        exec_path = ft_strjoin(path_prefix, cmd_split[0]);
        free(path_prefix);
        if (access(exec_path, F_OK | X_OK) == 0)
        {
            ft_free_tab(cmd_split);
            return (exec_path);
        }
        free(exec_path);
    }
    ft_free_tab(paths);
    ft_free_tab(cmd_split);
    return (cmd_name);
}
