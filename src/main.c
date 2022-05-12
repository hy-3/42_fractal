#include "../lib/minilibx_macos/mlx.h"
#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_vars	var;
	t_data	data;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "fractol");

	data.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	// -- put image --
	double x = 0;
	double y = 0;
	double c_re = 0;
	double c_im = 0;
	int n = 0;
	double k = y;
	
	while (x < WIDTH)
	{
		y = k;
		while (y < HEIGHT)
		{
			c_re = (x - WIDTH/2) * 4/WIDTH;
			c_im = (y - HEIGHT/2) * 4/WIDTH;
			n = mandelbrot(c_re, c_im);
			if (n == MAX_ITER)
				my_mlx_pixel_put(&data, x, y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(&data, x, y, 0x00000000);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(var.mlx, var.win, data.img, 0, 0);
	mlx_loop(var.mlx);

	return (0);
}


/*
ref:
 - https://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/
*/