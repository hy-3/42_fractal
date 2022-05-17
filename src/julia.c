#include "fractol.h"

double	calc_complex_num(double axis, double side, int axis_move, double zoom)
{
	double	res;

	if (HEIGHT > WIDTH)
		res = (axis - side / 2 + axis_move) * 4 / (WIDTH * zoom);
	else
		res = (axis - side / 2 + axis_move) * 4 / (HEIGHT * zoom);
	return (res);
}

int	is_julia(double complex_real, double complex_imagin)
{
	double	x;
	double	y;
	double	x_tmp;
	int		n;

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

void	create_julia_img(t_param *param)
{
	double	x;
	double	y;
	double	complex_r;
	double	complex_i;
	int		n;

	x = 0;
	complex_r = -0.5;
	complex_i = 0.3;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			complex_r = calc_complex_num(x, WIDTH, param->pos_x, param->zoom);
			complex_i = calc_complex_num(y, HEIGHT, param->pos_y, param->zoom);
			n = is_julia(complex_r, complex_i);
			put_color_on_pixel(param->data, x, y, n);
			y++;
		}
		x++;
	}
}


/*
ref: https://complex-analysis.com/content/julia_set.html
*/