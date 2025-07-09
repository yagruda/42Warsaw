/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/04/01 17:15:11 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc *.c -g -Lminilibx-linux -lmlx_Linux -lX11 -lXext

#include "fractol.h"

#define MALLOC_ERROR 1

int main(int ac, char **av)
{

	t_fractal fractal;

    if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || 
        (4 == ac && !ft_strncmp(av[1], "julia", 5)))
    {
		fractal.name = av[1];
        // Prompt correct usage
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
    }
    else
    {
        // Prompt incorrect usage
        putstr_fd(ERROR_MESSAGE, STDERR_FILENO); // TODO: Define ERROR_MESSAGE
        exit(EXIT_FAILURE);
    }
	// z and c have real and imaginary parts, so we'd be able to work real and imaginary parts separately
		
	return 0;
}