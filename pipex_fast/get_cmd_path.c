/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:13:11 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 13:13:13 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_env_path(char **envp, char **path_env)
{
	int	j;

	j = 0;
	*path_env = NULL;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			*path_env = envp[j] + 5;
			break ;
		}
		j++;
	}
}

static char	*search_cmd_path(char **paths, char *cmd)
{
	char	*full_path;
	char	*tmp;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		if (!full_path)
			break ;
		tmp = ft_strjoin(full_path, cmd);
		free(full_path);
		if (!tmp)
			break ;
		if (access(tmp, X_OK) == 0)
		{
			free_2d(paths);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*result;

	find_env_path(envp, &path_env);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	result = search_cmd_path(paths, cmd);
	if (!result)
		free_2d(paths);
	return (result);
}
