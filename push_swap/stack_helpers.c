/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:35:52 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/05 22:15:05 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct stack_node* ft_new_node(int data)
{
	struct stack_node* stack_node = malloc(sizeof(struct stack_node));
	if(!stack_node)
	{
		ft_printf("stack_node malloc failed\n");
		return (NULL);
	}
	stack_node->data = data;
	stack_node->next = NULL;

	return(stack_node);
}

void ft_free_stack(struct stack_node** head)
{
	struct stack_node* current;
	struct stack_node* next;

	current = *head;
	
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	free(current);
}

void ft_push(struct stack_node** top_ref, int value)
{
	struct stack_node* stack_node = ft_new_node(value);
	if(!stack_node) return;

	stack_node->next = *top_ref;
	*top_ref = stack_node;
	
	ft_printf("pushed %d into a stack_node %p \n", value, stack_node);
}

void ft_pop (struct stack_node** top_ref)
{
	struct stack_node* temporary;
	temporary = *top_ref;
	
	*top_ref = temporary->next;

	// we allocate memory making push, so we have to free making pop
	free(temporary);
	
}

// delete if not used
void ft_is_empty (struct stack_node** top_ref)
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

void ft_read_stack(struct stack_node** current)
{
	while (current != NULL)
	{
		ft_printf("I SEE %d READING A STACK 'A' \n", current->data);
		current = current->next; 
	}
}

