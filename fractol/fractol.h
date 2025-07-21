/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:46:58 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/21 11:13:30 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx/mlx.h"
#include "Libft/libft.h"
#include "printf/ft_printf.h"
#include <stdlib.h>

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_C 8
# define KEY_J 38
# define KEY_K 40
# define KEY_H 4
# define KEY_L 37

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_data {
    void    *img;           // MLX image pointer
    void    *addr;          // Actual pixel data
    int     bits_per_pixel; // Color depth
    int     line_length;    // Bytes per line
    int     endian;         // Byte ordering
} t_data;

typedef struct s_fractal {
    double min_re;          // Left boundary
    double max_re;          // Right boundary
    double min_im;          // Bottom boundary
    double max_im;          // Top boundary
    int max_iter;           // Maximum iterations for coloring
    double zoom;            // Current zoom level
    double move_x;          // Horizontal pan
    double move_y;          // Vertical pan
    char *type;            // "mandelbrot" or "julia"
    double julia_re;       // Julia set constant (real part)
    double julia_im;       // Julia set constant (imaginary part)
    int color_shift;        // Add this line
} t_fractal;


typedef struct s_vars {
    void *mlx;
    void *win;
    t_data img;
    t_fractal fractal;
} t_vars;

typedef struct s_calc_params
{
    double	zx;
    double	zy;
    double	cx;
    double	cy;
}	t_calc_params;

void	render_fractal(t_vars *vars);
void	render_pixel(t_vars *vars, int px, int py);
void	map_pixel_to_complex(t_vars *vars, int px, int py, double *x, double *y);
int	    calculate_fractal(t_vars *vars, double x, double y);
int	    get_color(int iterations, int max_iter, int color_shift);
int	ft_handle_mouse(int button, int x, int y, t_vars *vars);
void	init_fractal(t_vars *vars, char *type);
int	ft_handle_key(int keycode, t_vars *vars);
int	ft_close_window(t_vars *vars);

#endif