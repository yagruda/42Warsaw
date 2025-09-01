/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:23:21 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:23:22 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The lstadd_front() function adds the node (element) ’new’ 
at the beginning of the list. */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL | new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
