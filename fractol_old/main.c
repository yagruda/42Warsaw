/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/22 13:27:29 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int init_mlx(t_vars *vars, t_data *img)
{
    vars->mlx = mlx_init();                    
    if (!vars->mlx)
        return (1);
    
    vars->win = mlx_new_window(vars->mlx, 800, 600, "fractol");
    if (!vars->win)
        return (1);

    img->img = mlx_new_image(vars->mlx, 800, 600);
    img->addr = mlx_get_data_addr(img->img,
                                 &img->bits_per_pixel, 
                                 &img->line_length, 
                                 &img->endian);
    return (0);
}

int check_args(int ac, char **av)
{
    if((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
       (ac == 2 && !ft_strncmp(av[1], "julia", 5)))
    {
        return (0);
    }
    ft_printf("You have to provide a valid parameter from a list:\n");
    ft_printf(" mandelbrot\n julia\n");
    return (1);
}

int main(int ac, char** av)
{
    t_data img;
    t_vars vars;
    
    if (check_args(ac, av))
        return (1);
    
    if (init_mlx(&vars, &img))
        return (1);
    
    init_fractal(&vars, av[1]);
    vars.img = img;
    render_fractal(&vars);
    
    mlx_hook(vars.win, 2, 1L<<0, ft_handle_key, &vars);
    mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
    mlx_mouse_hook(vars.win, ft_handle_mouse, &vars);
    
    mlx_loop(vars.mlx);
    return (0);
}