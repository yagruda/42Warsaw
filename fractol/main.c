/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/21 11:13:35 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

You must be able to create different Julia sets by passing different parameters to
the program.

If no parameter is provided, or if the parameter is invalid, the program displays
a list of available parameters and exits properly. */

/* Main header file for the Fractol project
 * Includes necessary libraries and defines structures/prototypes
 */
#include "fractol.h"

/* Initialize MLX and create window
 * @param vars: Structure holding MLX pointers
 * @param img: Structure for MLX image handling
 * @return: 0 on success, 1 on failure
 *
 * Sets up:
 * - MLX connection
 * - Window creation (800x600)
 * - Image buffer for drawing
 */
int init_mlx(t_vars *vars, t_data *img)
{
    ft_printf("Calling mlx_init...\n");
    vars->mlx = mlx_init();                    // Initialize MLX
    if (!vars->mlx)
        return (1);                            // Return error if MLX init fails
    
    ft_printf("Calling mlx_new_window...\n");
    vars->win = mlx_new_window(vars->mlx, 800, 600, "Fractol");
    if (!vars->win)
        return (1);                            // Return error if window creation fails

    ft_printf("mlx_new image...\n");
    img->img = mlx_new_image(vars->mlx, 800, 600);  // Create image buffer
    img->addr = mlx_get_data_addr(img->img,         // Get image properties
                                 &img->bits_per_pixel, 
                                 &img->line_length, 
                                 &img->endian);
    return (0);
}

/* Validate command line arguments
 * @param ac: Argument count
 * @param av: Argument vector
 * @return: 0 if arguments valid, 1 if invalid
 *
 * Valid arguments:
 * - "mandelbrot"
 * - "julia"
 */
int check_args(int ac, char **av)
{
    if((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
       (ac == 2 && !ft_strncmp(av[1], "julia", 5)))
    {
        ft_printf("Hey you choosed mandelbrot or julia set!\n");
        return (0);
    }
    ft_printf("You have to provide a valid parameter from a list:\n");
    ft_printf(" mandelbrot\n julia\n");
    return (1);
}

/* Main program entry point
 * @param ac: Argument count
 * @param av: Argument vector
 * @return: 0 on success, 1 on error
 *
 * Program flow:
 * 1. Check command line arguments
 * 2. Initialize MLX and window
 * 3. Set up fractal parameters
 * 4. Render initial fractal
 * 5. Set up event hooks
 * 6. Enter main loop
 */
int main(int ac, char** av)
{
    t_data img;                                // MLX image data
    t_vars vars;                               // Program state variables
    
    if (check_args(ac, av))                    // Validate arguments
        return (1);
    
    if (init_mlx(&vars, &img))                 // Initialize MLX
        return (1);
    
    init_fractal(&vars, av[1]);                // Set up fractal parameters
    vars.img = img;                            // Store image data in vars
    render_fractal(&vars);                     // Draw initial fractal
    
    ft_printf("Attaching hooks\n");
    mlx_hook(vars.win, 2, 1L<<0, ft_handle_key, &vars);      // Keyboard events
    mlx_hook(vars.win, 17, 0, ft_close_window, &vars);       // Window close button
    mlx_mouse_hook(vars.win, ft_handle_mouse, &vars);        // Mouse events
    
    ft_printf("Calling mlx_loop...\n");
    mlx_loop(vars.mlx);                        // Enter main event loop
    return (0);
}