/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:46:58 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/31 14:53:55 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libftprintf/ft_printf.h"
# include "minilibx/mlx.h"
# include <stdlib.h>

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_C 99
# define KEY_J 106
# define KEY_K 107
# define KEY_H 104
# define KEY_L 108

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_data
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_fractal
{
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	int			max_iter;
	double		zoom;
	double		move_x;
	double		move_y;
	char		*type;
	double		julia_re;
	double		julia_im;
	int			color_shift;
}				t_fractal;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_fractal	fractal;
}				t_vars;

typedef struct s_calc_params
{
	double		zx;
	double		zy;
	double		cx;
	double		cy;
}				t_calc_params;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

void			render_fractal(t_vars *vars);
void			render_pixel(t_vars *vars, int px, int py);
void			map_pixel_to_complex(t_vars *vars, int px, int py,
					t_point *point);
int				calculate_fractal(t_vars *vars, double x, double y);
int				get_color(int iterations, int max_iter, int color_shift);
int				ft_handle_mouse(int button, int x, int y, t_vars *vars);
void			init_fractal(t_vars *vars, char *type);
int				ft_handle_key(int keycode, t_vars *vars);
int				ft_close_window(t_vars *vars);

#endif