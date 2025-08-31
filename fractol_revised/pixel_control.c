/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:49:45 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/31 14:57:17 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iterations, int max_iter, int color_shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iterations / max_iter;
	if (color_shift == 0)
	{
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (color_shift == 1)
	{
		r = (int)(9 * t * t * (1 - t) * 255);
		g = (int)(15 * t * (1 - t) * (1 - t) * 255);
		b = (int)(8.5 * t * t * t * 255);
	}
	else
	{
		r = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * t * t * t * 255);
	}
	return ((r << 16) | (g << 8) | b);
}

void	map_pixel_to_complex(t_vars *vars, int px, int py, t_point *point)
{
	point->x = (px * (vars->fractal.max_re - vars->fractal.min_re) / 800
			+ vars->fractal.min_re) * vars->fractal.zoom + vars->fractal.move_x;
	point->y = (py * (vars->fractal.max_im - vars->fractal.min_im) / 600
			+ vars->fractal.min_im) * vars->fractal.zoom + vars->fractal.move_y;
}

void	render_pixel(t_vars *vars, int px, int py)
{
	t_point	point;
	int		iterations;
	int		color;

	map_pixel_to_complex(vars, px, py, &point);
	iterations = calculate_fractal(vars, point.x, point.y);
	color = get_color(iterations, vars->fractal.max_iter,
			vars->fractal.color_shift);
	my_mlx_pixel_put(&vars->img, px, py, color);
}

void	render_fractal(t_vars *vars)
{
	int	px;
	int	py;

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
