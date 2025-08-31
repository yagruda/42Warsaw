/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:55:43 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/31 14:57:59 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_vars *vars, char *type)
{
	vars->fractal.min_re = -2.0;
	vars->fractal.max_re = 2.0;
	vars->fractal.min_im = -1.5;
	vars->fractal.max_im = 1.5;
	vars->fractal.max_iter = 50;
	vars->fractal.zoom = 1.0;
	vars->fractal.move_x = 0.0;
	vars->fractal.move_y = 0.0;
	vars->fractal.type = type;
	vars->fractal.julia_re = -0.4;
	vars->fractal.julia_im = 0.6;
	vars->fractal.color_shift = 0;
}

static void	set_fractal_params(t_vars *vars, double x, double y,
		t_calc_params *params)
{
	if (!ft_strncmp(vars->fractal.type, "mandelbrot", 10))
	{
		params->cx = x;
		params->cy = y;
		params->zx = 0;
		params->zy = 0;
	}
	else if (!ft_strncmp(vars->fractal.type, "julia", 5))
	{
		params->cx = vars->fractal.julia_re;
		params->cy = vars->fractal.julia_im;
		params->zx = x;
		params->zy = y;
	}
}

int	calculate_fractal(t_vars *vars, double x, double y)
{
	t_calc_params	params;
	double			tmp;
	int				i;

	set_fractal_params(vars, x, y, &params);
	i = 0;
	while (i < vars->fractal.max_iter && (params.zx * params.zx + params.zy
			* params.zy) < 4.0)
	{
		tmp = params.zx * params.zx - params.zy * params.zy + params.cx;
		params.zy = 2 * params.zx * params.zy + params.cy;
		params.zx = tmp;
		i++;
	}
	return (i);
}
