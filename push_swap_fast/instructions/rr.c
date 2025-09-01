/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:13:10 by yhruda          #+#    #+#             */
/*   Updated: 2025/09/01 12:45:37 by yhruda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rr(t_set *set)
{
	if (stack_size(set->a) < 2 || stack_size(set->b) < 2)
		return (-1);
	rotate(set->a);
	rotate(set->b);
	ft_print("rr\n");
	return (0);
}
