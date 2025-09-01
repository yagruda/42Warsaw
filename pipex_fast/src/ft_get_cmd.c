/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:20:16 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:29:04 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **envp)
{
	char	*envp_path;
	char	**path_parts;
	int		i;

	envp_path = NULL;
	path_parts = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
		{
			envp_path = ft_strdup(envp[i]);
			if (!envp_path)
				ft_error_message(E_ENVP, "Errno", 1);
			break ;
		}
		i++;
	}
	if (!envp_path)
		ft_error_message(E_ENVPATH, "Errno", 1);
	path_parts = ft_split(envp_path, ':');
	free(envp_path);
	return (path_parts);
}

char	*ft_get_cmd_path(char **envp, char *cmd_part)
{
	char	**path_parts;
	char	*check_path;
	char	*cmd;
	int		i;

	i = 0;
	if (access(cmd_part, F_OK | X_OK) == 0)
		return (cmd_part);
	path_parts = ft_get_path(envp);
	cmd = ft_strjoin("/", cmd_part);
	while (path_parts[i])
	{
		check_path = ft_strjoin(path_parts[i], cmd);
		if (access(check_path, F_OK | X_OK) == 0)
			break ;
		free (check_path);
		check_path = NULL;
		i++;
	}
	i = -1;
	while (path_parts[++i])
		free(path_parts[i]);
	free(path_parts);
	free (cmd);
	return (check_path);
}
