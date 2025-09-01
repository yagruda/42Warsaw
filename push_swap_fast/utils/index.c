/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:52:06 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:53:58 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*get_next_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack || !stack->top)
	{
		return (NULL);
	}
	current = stack->top;
	min_node = NULL;
	while (current)
	{
		if (current->index == -1 && (!min_node
				|| current->value < min_node->value))
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	index_stack(t_stack *a)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_next_min(a);
	while (head)
	{
		head->index = index++;
		head = get_next_min(a);
	}
}
