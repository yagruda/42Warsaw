/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:23:44 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/31 23:23:50 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void	ft_init_stack(t_data *new, t_stacks *stacks)
{
	stacks->a = ft_create_stack(new->a, new->count_element);
	stacks->b = NULL;
}

t_stack	*ft_create_stack(const int *buff, int count)
{
	int		i;
	t_stack	*new_list;
	t_stack	*first_element;

	i = 0;
	if (!(new_list = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	first_element = new_list;
	while (i < count)
	{
		if (i < count - 1)
		{
			if (!(new_list->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		}
		new_list->data = buff[i];
		if (i == (count - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (first_element);
}


void	ft_free_stack(t_stacks *stacks)
{
	int		i;
	t_stack	*buff;

	i = 0;
	while (i < stacks->count_a)
	{
		buff = stacks->a;
		stacks->a = stacks->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < stacks->count_b)
	{
		buff = stacks->b;
		stacks->b = stacks->b->next;
		free(buff);
		i++;
	}
}



void	ft_null(t_stacks *stacks, t_data *new)
{
	new->count_element = 0;
	stacks->count_a = 0;
	stacks->count_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->med = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}
