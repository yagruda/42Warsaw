/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:46:58 by yhruda            #+#    #+#             */
/*   Updated: 2025/07/21 11:33:09 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx/mlx.h"
#include "libftprintf/ft_printf.h"
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
    void    *img;
    void    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

typedef struct s_fractal {
    double min_re;
    double max_re;
    double min_im;
    double max_im;
    int max_iter;
    double zoom;
    double move_x;
    double move_y;
    char *type;
    double julia_re;
    double julia_im;
    int color_shift;
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