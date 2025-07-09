/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:26:33 by yhruda            #+#    #+#             */
/*   Updated: 2025/04/01 17:31:53 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_handler(int keysym, t_fractal *fractal)
{
	printf("%d\n", keysym);
	fprintf(stderr, "Key pressed: %d\n", keysym);
	return 0;
}