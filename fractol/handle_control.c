/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:50:56 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/21 11:09:50 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Mouse event handler for fractol
 * @param button: mouse button/scroll event code
 * @param x, y: mouse coordinates when event occurred
 * @param vars: program state containing fractal parameters
 * @return: 0 for successful handling
 */
int	ft_handle_mouse(int button, int x, int y, t_vars *vars)
{
    double	zoom_factor;    // Factor by which to zoom in/out
    double	mouse_re;       // Real part of mouse position in complex plane
    double	mouse_im;       // Imaginary part of mouse position in complex plane

    if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
    {
        // Convert screen coordinates to complex plane coordinates
        map_pixel_to_complex(vars, x, y, &mouse_re, &mouse_im);
        // Zoom in (1.2x) for scroll up, out (0.8x) for scroll down
        zoom_factor = (button == MOUSE_SCROLL_UP) ? 1.2 : 0.8;
        vars->fractal.zoom *= zoom_factor;
        // Adjust position to keep mouse point stationary during zoom
        vars->fractal.move_x += (mouse_re - vars->fractal.move_x) * (1 - zoom_factor);
        vars->fractal.move_y += (mouse_im - vars->fractal.move_y) * (1 - zoom_factor);
        render_fractal(vars);
    }
    return (0);
}

/* Window close handler
 * @param vars: program state containing MLX pointers
 * Cleans up MLX resources and exits program
 */
int	ft_close_window(t_vars *vars)
{
    ft_printf("Closing window...\n");
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

/* Keyboard event handler
 * @param keycode: key that was pressed
 * @param vars: program state containing fractal parameters
 * @return: 0 for successful handling
 * 
 * Controls:
 * ESC - Close window
 * Arrow keys - Move view
 * C - Cycle color schemes
 * For Julia set:
 *   H/L - Adjust real part of Julia constant
 *   J/K - Adjust imaginary part of Julia constant
 */
int	ft_handle_key(int keycode, t_vars *vars)
{
    if (keycode == KEY_ESC)
        ft_close_window(vars);
    else if (keycode == KEY_LEFT)
        vars->fractal.move_x -= 0.1 / vars->fractal.zoom;  // Move left
    else if (keycode == KEY_RIGHT)
        vars->fractal.move_x += 0.1 / vars->fractal.zoom;  // Move right
    else if (keycode == KEY_UP)
        vars->fractal.move_y -= 0.1 / vars->fractal.zoom;  // Move up
    else if (keycode == KEY_DOWN)
        vars->fractal.move_y += 0.1 / vars->fractal.zoom;  // Move down
    else if (keycode == KEY_C)
        vars->fractal.color_shift = (vars->fractal.color_shift + 1) % 3;  // Cycle colors
    // Julia set specific controls
    else if (keycode == KEY_H && !ft_strncmp(vars->fractal.type, "julia", 5))
        vars->fractal.julia_re -= 0.1;  // Decrease real part
    else if (keycode == KEY_L && !ft_strncmp(vars->fractal.type, "julia", 5))
        vars->fractal.julia_re += 0.1;  // Increase real part
    else if (keycode == KEY_J && !ft_strncmp(vars->fractal.type, "julia", 5))
        vars->fractal.julia_im += 0.1;  // Increase imaginary part
    else if (keycode == KEY_K && !ft_strncmp(vars->fractal.type, "julia", 5))
        vars->fractal.julia_im -= 0.1;  // Decrease imaginary part
    render_fractal(vars);  // Update display after any change
    return (0);
}