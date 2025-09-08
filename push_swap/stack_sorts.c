/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:23:50 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/08 12:29:08 by yhruda           ###   ########.fr       */
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
	(void)stack_a;
	// to be implemented
}
void ft_sort_turk(t_stack_node** stack_a, t_stack_node** stack_b)
{
	(void)stack_a;
	(void)stack_b;
	// to be implemented
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
