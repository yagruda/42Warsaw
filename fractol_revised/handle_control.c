/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:50:56 by yhruda            #+#    #+#             */
/*   Updated: 2025/08/31 14:55:52 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handle_mouse(int button, int x, int y, t_vars *vars)
{
	double	zoom_factor;
	t_point	mouse_point;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		map_pixel_to_complex(vars, x, y, &mouse_point);
		if (button == MOUSE_SCROLL_UP)
			zoom_factor = 1.2;
		else
			zoom_factor = 0.8;
		vars->fractal.zoom *= zoom_factor;
		vars->fractal.move_x += (mouse_point.x - vars->fractal.move_x) * (1
				- zoom_factor);
		vars->fractal.move_y += (mouse_point.y - vars->fractal.move_y) * (1
				- zoom_factor);
		render_fractal(vars);
	}
	return (0);
}

int	ft_close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_handle_key(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		ft_close_window(vars);
	else if (keycode == KEY_LEFT)
		vars->fractal.move_x -= 0.1 / vars->fractal.zoom;
	else if (keycode == KEY_RIGHT)
		vars->fractal.move_x += 0.1 / vars->fractal.zoom;
	else if (keycode == KEY_UP)
		vars->fractal.move_y -= 0.1 / vars->fractal.zoom;
	else if (keycode == KEY_DOWN)
		vars->fractal.move_y += 0.1 / vars->fractal.zoom;
	else if (keycode == KEY_C)
		vars->fractal.color_shift = (vars->fractal.color_shift + 1) % 3;
	else if (keycode == KEY_H && !ft_strncmp(vars->fractal.type, "julia", 5))
		vars->fractal.julia_re -= 0.1;
	else if (keycode == KEY_L && !ft_strncmp(vars->fractal.type, "julia", 5))
		vars->fractal.julia_re += 0.1;
	else if (keycode == KEY_J && !ft_strncmp(vars->fractal.type, "julia", 5))
		vars->fractal.julia_im += 0.1;
	else if (keycode == KEY_K && !ft_strncmp(vars->fractal.type, "julia", 5))
		vars->fractal.julia_im -= 0.1;
	render_fractal(vars);
	return (0);
}
