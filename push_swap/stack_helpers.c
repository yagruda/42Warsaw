/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:35:52 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/09 15:26:38 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void append_node(t_stack_node **stack, int n)
{
    t_stack_node* node;
    t_stack_node* last_node;

    if(!stack)
        return;
    node = malloc(sizeof(t_stack_node));
    if(!node)
        return;
    node->nbr = n;
    node->next = NULL;
    if(!*stack)
    {
        *stack = node;
        node->prev = NULL;
    }
    else 
    {
        last_node = find_last(*stack);
        last_node->next = node; 
        node->prev = last_node; 
    }
}

t_stack_node	*get_cheapest(t_stack_node *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b, false); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b, false); //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current node positions
	current_index(*b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b, false); 
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack_node	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target_node->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_both(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, false);
}

void	min_on_top(t_stack_node **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a, false);
		else
			rra(a, false);
	}
}

int	stack_len(t_stack_node *stack) //Define a function that calculates and returns the length of a stack
{
	int	count; //To store the node count

	if (!stack) 
		return (0);
	count = 0;
	while (stack) //Loop until the end of the stack is reached
	{
		stack = stack->next; //Move to the next node
		count++;
	}
	return (count);
}

t_stack_node* find_last(t_stack_node* stack)
{
    if (!stack)
        return (NULL);

    while (stack->next != NULL)
        stack = stack->next;
    return (stack);
}

t_stack_node* find_max(t_stack_node* stack)
{
	long max;
	t_stack_node* max_node;

	if (!stack)
		return (NULL);
	
	// -9223372036854775808
	max = LONG_MIN;
	
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}	
		stack = stack->next;
	}

	return (max_node);
}

t_stack_node* find_min(t_stack_node* stack)
{
    long min;
    t_stack_node* min_node;

    if(!stack)
        return (NULL);

    // 9223372036854775807
    min = LONG_MAX;

    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}


// delete if not used
void ft_is_empty (t_stack_node** top_ref)
{
    if (*top_ref == NULL)
    {
        ft_printf("FT_IS_EMPTY SAY STACK IS EMPTY");
    }
    else 
    {
        ft_printf("FT_IS_EMPTY SAY STACK IS NOT EMPTY");
    }
}

void ft_read_stack(t_stack_node* current)
{
    while (current != NULL)
    {
        ft_printf("I SEE %d READING A STACK 'A' \n", current->nbr);
        current = current->next; 
    }
}


