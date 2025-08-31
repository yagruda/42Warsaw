/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:14:31 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/31 23:14:32 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	finish(char **str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		tmp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = NULL;
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	returns(char **str, char **line, int val, int fd)
{
	if (val < 0)
		return (-1);
	else if (val == 0 && str[fd] == NULL)
		return (0);
	else
		return (finish(&str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			val;
	static char	*str[12000];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((val = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[val] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (returns(str, line, val, fd));
}
