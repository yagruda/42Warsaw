/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:13:29 by yhruda          #+#    #+#             */
/*   Updated: 2025/09/01 12:45:37 by yhruda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrr(t_set *set)
{
	if (stack_size(set->a) < 2 || stack_size(set->b) < 2)
		return (-1);
	reverse_rotate(set->a);
	reverse_rotate(set->b);
	ft_print("rrr\n");
	return (0);
}
