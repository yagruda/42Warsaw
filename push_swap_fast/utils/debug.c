/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:27 by yhruda          #+#    #+#             */
/*   Updated: 2025/09/01 12:45:37 by yhruda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_node *top)
{
	t_node	*current;

	if (!top)
	{
		printf("Stack is empty\n");
		printf("------------------\n");
		return ;
	}
	printf("Stack Top\n");
	printf("------------------\n");
	current = top;
	while (current)
	{
		printf("│ %d\n", current->value);
		printf("│ ↓\n");
		current = current->next;
	}
	printf("------------------\n");
	printf("Stack Bottom\n");
}
