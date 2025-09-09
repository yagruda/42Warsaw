/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:30:47 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/08 17:32:45 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
	t_stack_node* first;
	t_stack_node* last;

	if ((!stack) || (*stack)->next == NULL)
		return ;

	first = *stack;
	last = find_last(*stack);
	
	*stack = last;
	last = first;
	
}

void rra(t_stack_node** a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void rrb(t_stack_node** b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void rrr(t_stack_node** a, t_stack_node** b, bool print)
{
	rra(a, print);
	rrb(b, print);
	if (!print)
		ft_printf("rrr\n");
}
