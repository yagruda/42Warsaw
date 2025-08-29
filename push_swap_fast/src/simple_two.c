/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:25:11 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/26 17:10:29 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
    int	distance;

    if (is_sorted(stack_a))
        return ;
    distance = get_distance(stack_a, get_min(stack_a, -1));
    if (distance == 1)
        ra(stack_a);
    else if (distance == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (distance == 3)
        rra(stack_a);
    if (is_sorted(stack_a))
        return ;
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
    int	distance;

    distance = get_distance(stack_a, get_min(stack_a, -1));
    if (distance == 1)
        ra(stack_a);
    else if (distance == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (distance == 3)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if (distance == 4)
        rra(stack_a);
    if (is_sorted(stack_a))
        return ;
    pb(stack_a, stack_b);
    sort_4(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
    int	size;

    if (is_sorted(stack_a) || ft_lstsize(*stack_a) < 2)
        return ;
    size = ft_lstsize(*stack_a);
    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_3(stack_a);
    else if (size == 4)
        sort_4(stack_a, stack_b);
    else if (size == 5)
        sort_5(stack_a, stack_b);
}