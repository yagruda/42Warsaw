/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:49:45 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/21 11:13:33 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function puts a single pixel on the image
 * @param data: MLX image data structure
 * @param x, y: coordinates where to put the pixel
 * @param color: RGB color value to set
 * The function calculates the exact memory position where to write the color
 * based on the image properties (bits per pixel, line length)
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;
    // Calculate memory position using the formula:
    // position = start + (y * line_width + x * (bits_per_pixel / 8))
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

/* Converts iteration count to RGB color using smooth coloring algorithm
 * @param iterations: current iteration count
 * @param max_iter: maximum iteration limit
 * @param color_shift: changes color palette (0-2)
 * Returns: 24-bit RGB color value
 * Uses different color formulas based on color_shift value
 */
int	get_color(int iterations, int max_iter, int color_shift)
{
    double	t;  // Normalized iteration count (0.0 to 1.0)
    int		r;  
    int		g;  
    int		b;  

    t = (double)iterations / max_iter;
    if (color_shift == 0)  // First color palette
    {
        r = (int)(9 * (1 - t) * t * t * t * 255);
        g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }
    else if (color_shift == 1)  // Second color palette
    {
        r = (int)(9 * t * t * (1 - t) * 255);
        g = (int)(15 * t * (1 - t) * (1 - t) * 255);
        b = (int)(8.5 * t * t * t * 255);
    }
    else  // Third color palette
    {
        r = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
        g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b = (int)(8.5 * (1 - t) * t * t * t * 255);
    }
    // Combine RGB components into single color value
    return ((r << 16) | (g << 8) | b);
}

/* Converts screen coordinates to complex plane coordinates
 * @param vars: program state containing fractal parameters
 * @param px, py: screen coordinates
 * @param x, y: pointers to store resulting complex coordinates
 * Takes into account current zoom level and position offset
 */
void	map_pixel_to_complex(t_vars *vars, int px, int py, double *x, double *y)
{
    // Convert from pixel coordinates to complex plane coordinates
    // Apply zoom and movement transformations
    *x = (px * (vars->fractal.max_re - vars->fractal.min_re) / 800 + vars->fractal.min_re) 
         * vars->fractal.zoom + vars->fractal.move_x;
    *y = (py * (vars->fractal.max_im - vars->fractal.min_im) / 600 + vars->fractal.min_im) 
         * vars->fractal.zoom + vars->fractal.move_y;
}

/* Renders a single pixel of the fractal
 * @param vars: program state
 * @param px, py: pixel coordinates to render
 * Combines coordinate mapping, fractal calculation, and color rendering
 */
void render_pixel(t_vars *vars, int px, int py)
{
    double x;
    double y;
    
    map_pixel_to_complex(vars, px, py, &x, &y);
    int iterations = calculate_fractal(vars, x, y);
    int color = get_color(iterations, vars->fractal.max_iter, vars->fractal.color_shift);
    my_mlx_pixel_put(&vars->img, px, py, color);
}

/* Renders the entire fractal
 * @param vars: program state
 * Iterates through all pixels of the window (800x600)
 * Renders each pixel and updates the window
 */
void render_fractal(t_vars *vars)
{
    int px;
    int py;

    py = 0;
    while (py < 600)  
    {
        px = 0;
        while (px < 800)  
        {
            render_pixel(vars, px, py);
            px++;
        }
        py++;
    }
    
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}