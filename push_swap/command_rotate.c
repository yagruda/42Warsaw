/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:11:29 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/09 12:03:28 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TBD
//function that rotates the stack's top node to the bottom of the stack
static void rotate(t_stack_node **stack_head)
{
	if ((!stack_head) || (*stack_head)->next == NULL)
		return; // if stack is empty or has only one element, do nothing
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


