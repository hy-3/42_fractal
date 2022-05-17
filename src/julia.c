#include "fractol.h"

double	j_calc_complex_num(double axis, double side, int axis_move, double zoom)
{
	double	res;

	if (HEIGHT > WIDTH)
		res = (axis - side / 2 + axis_move) * 4 / (WIDTH * zoom);
	else
		res = (axis - side / 2 + axis_move) * 4 / (HEIGHT * zoom);
	return (res);
}

int	is_julia(double x, double y, double complex_real, double complex_imagin)
{
	double	x_tmp;
	int		n;

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

void	j_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	j_put_color_on_pixel(t_data *data, double x, double y, int n)
{
	if (n == MAX_ITER)
		j_my_mlx_pixel_put(data, x, y, INSIDE_COLOR);
	else
		j_my_mlx_pixel_put(data, x, y, OUTSIDE_COLOR);
}

void	create_julia_img(t_param *param)
{
	double	x;
	double	y;
	double	complex_r;
	double	complex_i;
	int		n;

	x = 0;
	complex_r = 0.318;
	complex_i = 0.089;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			n = is_julia( \
					j_calc_complex_num(x, WIDTH, param->pos_x, param->zoom), \
					j_calc_complex_num(y, HEIGHT, param->pos_y, param->zoom), \
					complex_r, complex_i);
			j_put_color_on_pixel(param->data, x, y, n);
			y++;
		}
		x++;
	}
}
