/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:11:29 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/09 14:50:36 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
PSEUDO-CODE:

create last variable and assign to a last node using find_last function.
E.g NULL <- 3 <-> 2 <-> 1 -> NULL; 

last would point to node which contains 1.
stack_head would point to a node which contains 3.




*/
//function that rotates the stack's top node to the bottom of the stack
static void rotate(t_stack_node **stack_head)
{
	t_stack_node* last;
	
	if ((!*stack_head) || (*stack_head)->next == NULL)
		return; // if stack is empty or has only one element, do nothing
	
	last = find_last(*stack_head);

	last->next = *stack_head;
		
	*stack_head = (*stack_head)->next;
	(*stack_head)->prev = NULL;

	last->next->prev = last;
	last->next->next = NULL;
}
	
void ra(t_stack_node** a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void rb(t_stack_node** b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void rr(t_stack_node** a, t_stack_node** b, bool print)
{
	ra(a, print);
	rb(b, print);
	if (!print)
		ft_printf("rr\n");
}


