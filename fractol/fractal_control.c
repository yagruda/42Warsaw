/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:55:43 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/21 11:11:45 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Initialize fractal parameters
 * @param vars: program state structure
 * @param type: string indicating fractal type ("mandelbrot" or "julia")
 * Sets up initial viewing window, zoom level, and fractal-specific parameters
 */
void init_fractal(t_vars *vars, char *type)
{
    vars->fractal.min_re = -2.0;    // Left boundary of view window
    vars->fractal.max_re = 2.0;     // Right boundary of view window
    vars->fractal.min_im = -1.5;    // Bottom boundary of view window
    vars->fractal.max_im = 1.5;     // Top boundary of view window
    vars->fractal.max_iter = 50;    // Maximum iterations for escape-time calculation
    vars->fractal.zoom = 1.0;       // Initial zoom level (1.0 = no zoom)
    vars->fractal.move_x = 0.0;     // Initial X offset (0 = centered)
    vars->fractal.move_y = 0.0;     // Initial Y offset (0 = centered)
    vars->fractal.type = type;      // Store fractal type
    vars->fractal.julia_re = -0.4;  // Julia set constant, real part
    vars->fractal.julia_im = 0.6;   // Julia set constant, imaginary part
    vars->fractal.color_shift = 0;  // Initial color palette selection
}

/* Set up parameters for fractal calculation based on type
 * @param vars: program state containing fractal type
 * @param x, y: coordinates in complex plane
 * @param params: structure to store calculation parameters
 * 
 * For Mandelbrot set:
 *   - c = x + yi (point coordinates)
 *   - z starts at 0
 * For Julia set:
 *   - c is fixed (julia_re + julia_im*i)
 *   - z starts at x + yi (point coordinates)
 */
static void	set_fractal_params(t_vars *vars, double x, double y,
                            t_calc_params *params)
{
    if (!ft_strncmp(vars->fractal.type, "mandelbrot", 10))
    {
        params->cx = x;         // c.real = x
        params->cy = y;         // c.imag = y
        params->zx = 0;         // z starts at 0
        params->zy = 0;
    }
    else if (!ft_strncmp(vars->fractal.type, "julia", 5))
    {
        params->cx = vars->fractal.julia_re;  // c = constant
        params->cy = vars->fractal.julia_im;
        params->zx = x;         // z starts at point coordinates
        params->zy = y;
    }
}

/* Calculate fractal iteration count for a point
 * @param vars: program state
 * @param x, y: coordinates in complex plane
 * @return: number of iterations before escape
 * 
 * Uses the formula z = z² + c repeatedly
 * Counts iterations until |z| > 2 or max_iter reached
 * This is the core fractal computation function
 */
int	calculate_fractal(t_vars *vars, double x, double y)
{
    t_calc_params	params;  // Holds z and c values
    double			tmp;     // For storing intermediate calculation
    int				i;       // Iteration counter

    set_fractal_params(vars, x, y, &params);
    i = 0;
    // Continue until escape (|z| > 2) or max iterations reached
    while (i < vars->fractal.max_iter
        && (params.zx * params.zx + params.zy * params.zy) < 4.0)
    {
        // Calculate z = z² + c
        tmp = params.zx * params.zx - params.zy * params.zy + params.cx;
        params.zy = 2 * params.zx * params.zy + params.cy;
        params.zx = tmp;
        i++;
    }
    return (i);  // Return iteration count for coloring
}