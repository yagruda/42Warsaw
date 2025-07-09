/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:42:56 by yhruda            #+#    #+#             */
/*   Updated: 2025/04/01 17:29:49 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // TODO debugging
# include <stdlib.h> // malloc free
# include <unistd.h> // write 
# include <math.h> 
# include "minilibx-linux/mlx.h"
# include "X11/X.h"

#define BLACK 0x000000
#define WHITE 0xFFFFFF

// Base psychedelic colors
#define PSY_RED        0xFF007F  // Neon Pink-Red
#define PSY_ORANGE     0xFF6600  // Bright Orange
#define PSY_YELLOW     0xFFFF00  // Neon Yellow
#define PSY_GREEN      0x00FF00  // Electric Green
#define PSY_CYAN       0x00FFFF  // Neon Cyan
#define PSY_BLUE       0x0000FF  // Bright Blue
#define PSY_PURPLE     0x8000FF  // Vivid Purple

// Extra neon psychedelic shades
#define PSY_MAGENTA    0xFF00FF  // Fluorescent Magenta
#define PSY_TEAL       0x008080  // Deep Teal
#define PSY_LIME       0xBFFF00  // Neon Lime
#define PSY_PINK       0xFF1493  // Deep Pink
#define PSY_AQUA       0x00FFBF  // Aqua Glow
#define PSY_VIOLET     0x9400D3  // Intense Violet

// Gradient variations for smooth transitions
#define PSY_GRADIENT1  0xFF33CC  // Pinkish Violet
#define PSY_GRADIENT2  0xCC33FF  // Purple-Pink Glow
#define PSY_GRADIENT3  0x33FFFF  // Electric Blue Glow
#define PSY_GRADIENT4  0x66FF33  // Acid Green
#define PSY_GRADIENT5  0xFF3366  // Deep Neon Pink


#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

// Square to keep rendering math simple
#define WIDTH 800
#define HEIGHT 800

typedef struct s_img
{
	void *img_ptr; // pointer to the image
	char *pixels_ptr; // pointer to the pixel data
	int bpp; // bits per pixel
	int endian; 
	int line_len; // size of one line in bytes
}	t_img;

typedef struct s_fractal
{
	// t_img is a structure that contains information about the image, from above.
	t_img img; 
	
	char* name;
	// MLXs is generic pointer and can be any type of data
	void *mlx_connection; 
	void *mlx_window;

	// Hooks member variables
	//hypothenuse 
	double escape_value; 
	double iterations_defintion;
	
}	t_fractal;

typedef struct s_complex
{
	// real
	double x;
	// imaginary 
	double y;
} t_complex;


int key_handler(int keysym, t_fractal *fractal);
void	fractal_render (t_fractal *fractal);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex (t_complex z);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
int ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

void fractal_init(t_fractal *fractal);

#endif