/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:23:31 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:23:34 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The lstdelone() function takes as a parameter a node and frees the memory 
of the node’s content using the function ’del’ given as a parameter 
and free the node. The memory of ’next’ must not be freed. */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	if (del != NULL)
		(del)(lst->content);
	free(lst);
}
