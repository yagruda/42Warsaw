/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:10:50 by yhruda            #+#    #+#             */
/*   Updated: 2025/04/01 15:18:27 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// [0..799] -> [-2..2]

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

// Sum Complex. It returns a structure of type t_complex which are x and y

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;
	
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return result;
}

// real = (x^2 - y^2)
// i = (2xy)
t_complex square_complex (t_complex z)
{
	t_complex result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return result;
}