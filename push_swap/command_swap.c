/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:37:05 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/08 15:33:19 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements
*/

// static because we wouldn't use it outside this file
static void swap(t_stack_node** head)
{	
	t_stack_node* element_f;
	t_stack_node* element_s;

	element_f = *head;
	element_s = (*head)->next;

	if (element_f == NULL || element_s == NULL)
		return ; // if there is only one or no elements, do nothing
	element_f->next = element_s->next;
	element_f->
	
}

void sa(t_stack_node** a, bool print)
{
	
	swap(a);	
	if (!print)
		ft_printf("sa\n");
}

void sb(t_stack_node** b, bool print)
{
	(void)b;
	(void)print;
	swap(b);
	// TBD
}

//Stimutaneously swap the first two nodes of the stack and print the instruction
void ss(t_stack_node** a, t_stack_node** b, bool print)
{
	(void)a;
	(void)b;
	(void)print;
	// TBD
}
