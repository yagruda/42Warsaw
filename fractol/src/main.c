/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/15 18:41:30 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

You must be able to create different Julia sets by passing different parameters to
the program.

If no parameter is provided, or if the parameter is invalid, the program displays
a list of available parameters and exits properly. */

#include "minilibx/mlx.h"
#include "Libft/libft.h"
#include "printf/ft_printf.h"

#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	ft_close( t_vars *vars)
{
    // TBD: add int input to handle the specific key event
    // TBD: Fix segmentation fault
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(int ac, char** av)
{

    t_vars vars;
    
    
    if((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
        (ac == 2 && !ft_strncmp(av[1], "julia", 5)))
    {
        printf("Hey you choosed mandelbrot or julia set!\n");
    }
    else
    {
        ft_printf("You have to provide a valid parameter from a list: \n Mandelbrot \n Julia \n");
        // return (1);
    }
    
    printf("Calling mlx_init...\n");
    vars.mlx = mlx_init();
    if (!vars.mlx)
    {
        printf("mlx_init failed\n");
        return (1);
    }

    printf("Calling mlx_new_window...\n");
    vars.win = mlx_new_window(vars.mlx, 800, 600, "Fractol");
    if (!vars.win)
    {
        printf("mlx_new_window failed\n");
        return (1);
    }

    printf("Calling mlx_pixel_put...\n");
    mlx_pixel_put(vars.mlx, vars.win, 800 / 2, 800 / 2, 0x00FF00);



    ft_printf("Attaching hooks\n");
    mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);

    
    printf("Calling mlx_loop...\n");
    mlx_loop(vars.mlx);

    printf("Exiting program...\n");

    return (0);
}