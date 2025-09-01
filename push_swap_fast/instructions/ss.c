/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:11:44 by yhruda          #+#    #+#             */
/*   Updated: 2025/09/01 12:45:37 by yhruda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ss(t_set *set)
{
	if (stack_size(set->a) < 2 || stack_size(set->b) < 2)
		return (-1);
	swap(set->a);
	swap(set->b);
	ft_print("ss\n");
	return (0);
}
