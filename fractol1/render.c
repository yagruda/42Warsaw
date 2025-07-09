#include "fractol.h"

// put a pixel in an image buffer
static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;

}


/*
-----800------
|            |
|            |
|            |
|            |
|            |
|            |
--------------

*/

void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	double color;

	i = 0;
	

	// 1 iteration
	z.x = 0.0;
	z.y = 0.0;

	// pixel coordinate x && y scaled to fit mandel needs
	c.x = map(x,-2, +2, 0, WIDTH);
	c.y = map(y, -2, +2, 0, HEIGHT);

	// How many times to iterate z^2 + c to check if the point escapes
	while (i < fractal->iterations_defintion)
	{
		// z = z^2 + c 
		z = sum_complex(square_complex(z), c);

		// is the value escaped??
		// if hyptenuse > 2 i assume the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_defintion);
			my_pixel_put(x, y, &fractal->img, color); // Todo
			return ;
		}
		++i;
	}
	// We are in Mandlebrot set 
	my_pixel_put(x, y, &fractal->img, PSY_MAGENTA);


}

void	fractal_render (t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x,y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr,0,0);
}