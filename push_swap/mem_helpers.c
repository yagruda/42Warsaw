/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:18:43 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/09 13:16:21 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_arr(char** arr)
{
	int i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

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