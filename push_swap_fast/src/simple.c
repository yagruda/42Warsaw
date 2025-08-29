/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:55:19 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/26 17:20:42 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list **stack, int val)
{
    t_list	*head;
    int		min;

    head = *stack;
    min = head->index;
    while (head->next)
    {
        head = head->next;
        if ((head->index < min) && head->index != val)
            min = head->index;
    }
    return (min);
}

static void	handle_max_top(t_list **stack_a, int min)
{
    if ((*stack_a)->next->index == min)
        ra(stack_a);
    else
    {
        sa(stack_a);
        rra(stack_a);
    }
}

static void	handle_next_min_top(t_list **stack_a, int min)
{
    if ((*stack_a)->next->index == min)
        sa(stack_a);
    else
        rra(stack_a);
}

static void	sort_3_handler(t_list **stack_a, int min, int next_min)
{
    t_list	*head;

    head = *stack_a;
    if (head->index == min)
    {
        ra(stack_a);
        sa(stack_a);
        rra(stack_a);
    }
    else if (head->index == next_min)
        handle_next_min_top(stack_a, min);
    else
        handle_max_top(stack_a, min);
}

void	sort_3(t_list **stack_a)
{
    int		min;
    int		next_min;

    if (is_sorted(stack_a))
        return ;
    min = get_min(stack_a, -1);
    next_min = get_min(stack_a, min);
    sort_3_handler(stack_a, min, next_min);
}