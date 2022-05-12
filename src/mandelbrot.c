#include "fractol.h"

double	calc_complex_num(double axis, double direction)
{
	double res;

	if (HEIGHT > WIDTH)
		res = (axis - direction / 2) * 4 / WIDTH;
	else
		res = (axis - direction / 2) * 4 / HEIGHT;
	return (res);
}

int	is_mandelbrot(double complex_real, double complex_imagin)
{
	double	x;
	double	y;
	double	x_tmp;
	int	n;

	x = 0;
	y = 0;
	n = 0;
	while ((x * x + y * y) <= 4 && n < (int)MAX_ITER)
	{
		x_tmp = x * x - y * y + complex_real;
		y = 2 * x * y + complex_imagin;
		x = x_tmp;
		n++;
	}
	return (n);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_color_on_pixel(t_data *data, double x, double y, int n)
{
	if (n == MAX_ITER)
		my_mlx_pixel_put(data, x, y, INSIDE_COLOR);
	else
		my_mlx_pixel_put(data, x, y, OUTSIDE_COLOR);
}

void	create_mandelbrot_img(t_data *data)
{
	double x;
	double y;
	double complex_real;
	double complex_imagin;
	int n;

	x = 0;
	complex_real = 0;
	complex_imagin = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			complex_real = calc_complex_num(x, WIDTH);
			complex_imagin = calc_complex_num(y, HEIGHT);
			n = is_mandelbrot(complex_real, complex_imagin);
			put_color_on_pixel(data, x, y, n);
			y++;
		}
		x++;
	}
}
