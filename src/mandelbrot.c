/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:46 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/18 11:56:38 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calc_complex_num_x(double x, int axis_move, double zoom)
{
	double	res;

	if (HEIGHT > WIDTH)
		res = (x - WIDTH / 2 + axis_move) * 4 / (WIDTH * zoom);
	else
		res = (x - WIDTH / 2 + axis_move) * 4 / (HEIGHT * zoom);
	return (res);
}

double	calc_complex_num_y(double y, int axis_move, double zoom)
{
	double	res;

	if (HEIGHT > WIDTH)
		res = (y - HEIGHT / 2 + axis_move) * -4 / (WIDTH * zoom);
	else
		res = (y - HEIGHT / 2 + axis_move) * -4 / (HEIGHT * zoom);
	return (res);
}

int	is_mandelbrot(double complex_r, double complex_i)
{
	double	x;
	double	y;
	double	x_tmp;
	int		n;

	x = complex_r;
	y = complex_i;
	n = 0;
	while ((x * x + y * y) <= 4 && n < (int)MAX_ITER)
	{
		x_tmp = x * x - y * y + complex_r;
		y = 2 * x * y + complex_i;
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

void	create_mandelbrot_img(t_param *param)
{
	double	x;
	double	y;
	double	complex_r;
	double	complex_i;
	int		n;

	x = 0;
	complex_r = 0;
	complex_i = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			complex_r = calc_complex_num_x(x, param->pos_x, param->zoom);
			complex_i = calc_complex_num_y(y, param->pos_y, param->zoom);
			n = is_mandelbrot(complex_r, complex_i);
			put_color_on_pixel(param->data, x, y, n);
			y++;
		}
		x++;
	}
}
