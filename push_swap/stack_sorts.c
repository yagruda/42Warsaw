/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:23:50 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/09 15:20:09 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_stack_sorted(t_stack_node* stack)
{
	while (stack != NULL)
	{
		if (stack->next != NULL && stack->nbr > stack->next->nbr)
		{
			ft_printf("stack is NOT sorted\n");
			return (0);
		}
		stack = stack->next;
	}
	ft_printf("stack is sorted\n");
	return 1;
}



void ft_sort_three(t_stack_node** stack_a)
{
	t_stack_node* biggest_node;
	
	biggest_node = find_max(*stack_a);

	if (biggest_node == *stack_a) // biggest is first
		ra(stack_a, false);
	else if ((*stack_a)->next == biggest_node) // biggest is second
		rra(stack_a, false);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, false);

		
}
void	ft_sort_turk(t_stack_node **stack_a, t_stack_node **stack_b) //Define a function that sorts stack `a` if it has more than 3 nodes
{
	int	len_a; //To store the length of stack `a`

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !ft_is_stack_sorted(*stack_a)) //If stack `a` has more than three nodes and aren't sorted
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && !ft_is_stack_sorted(*stack_a)) //If stack `a` still has more than three nodes and aren't sorted
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !ft_is_stack_sorted(*stack_a)) //If stack `a` still has more than three nodes and aren't sorted
	{
		init_nodes_a(*stack_a, *stack_b); //Iniate all nodes from both stacks
		move_a_to_b(stack_a, stack_b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	ft_sort_three(stack_a);
	while (*stack_b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*stack_a, *stack_b); //Initiate all nodes from both stacks
		move_b_to_a(stack_a, stack_b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*stack_a); //Refresh the current position of stack `a`
	min_on_top(stack_a); //Ensure smallest number is on top
}


void ft_sort_stack(t_stack_node** stack_a, t_stack_node** stack_b, int arguments_count)
{
	if (arguments_count == 0)
	{
		ft_printf("fck");
		ft_error();
	}	
	else if (arguments_count == 1)
		return ; // if we have only one number, we don't need to sort it
	else if (arguments_count == 2)
		sa(stack_a,false);
	else if(arguments_count == 3)
		ft_sort_three(stack_a);
	else if(arguments_count > 3)
		ft_sort_turk(stack_a, stack_b);
}
