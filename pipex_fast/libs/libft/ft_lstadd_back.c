/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:23:16 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:23:17 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The lstadd_back() function adds the node ’new’ at the end of the list. */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (*lst != NULL)
	{
		t = ft_lstlast(*lst);
		t->next = new;
	}
	else
		*lst = new;
}
