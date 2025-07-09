#include "fractol.h"


// if Malloc goes wrong

static void malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void data_init (t_fractal *fractal)
{
	fractal->escape_value = 4; // 2 ^ 2 my hyptohenuse
	fractal->iterations_defintion = 42; 
}

static void events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
//	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handle, fractal);	
//	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handle, fractal);
}

void fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if(fractal->mlx_connection == NULL)
		malloc_error(); //TODO
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
	if(fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error(); 
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if(fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	
	//events_init(fractal); //TODO
	data_init(fractal); //TODO

}