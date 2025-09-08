/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:35:52 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/08 15:16:04 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node* ft_new_node(int nbr)
{
    t_stack_node* stack_node = malloc(sizeof(t_stack_node));
    if(!stack_node)
    {
        ft_printf("stack_node malloc failed\n");
        return (NULL);
    }
    stack_node->nbr = nbr;
    stack_node->next = NULL;

    return(stack_node);
}

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

t_stack_node* find_last(t_stack_node* stack)
{
    if (!stack)
        return (NULL);

    while (stack->next != NULL)
        stack = stack->next;
    return (stack);
}
/*
t_stack_node* find_max(t_stack_node* stack)
{
    if (!stack)
        return (NULL);
    
    int max = stack->nbr;
}
*/

void ft_free_stack(t_stack_node** head)
{
    t_stack_node* current;
    t_stack_node* next;

    current = *head;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(current);
}

void ft_pop (t_stack_node** top_ref)
{
    t_stack_node* temporary;
    temporary = *top_ref;
    
    *top_ref = temporary->next;

    // we allocate memory making push, so we have to free making pop
    free(temporary);
    
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

