/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:46 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/18 15:12:00 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double axis, double axis_move, double zoom, int flag)
{
	double	res;

	if (HEIGHT > WIDTH)
	{
		if (flag == 0)
			res = (axis - WIDTH / 2) * 4 / (WIDTH * zoom) + axis_move;
		else if (flag == 1)
			res = (axis - HEIGHT / 2) * -4 / (WIDTH * zoom) + axis_move;
	}
	else
	{
		if (flag == 0)
			res = (axis - WIDTH / 2) * 4 / (HEIGHT * zoom) + axis_move;
		else if (flag == 1)
			res = (axis - HEIGHT / 2) * -4 / (HEIGHT * zoom) + axis_move;
	}
	return (res);
}

int	is_within_set(double x, double y, double complex_r, double complex_i)
{
	double	x_tmp;
	int		n;

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

void	put_color_on_pixel(t_data *data, int x, int y, int n)
{
	if (n == MAX_ITER)
		my_mlx_pixel_put(data, x, y, INSIDE_COLOR);
	else
		my_mlx_pixel_put(data, x, y, OUTSIDE_COLOR);
}

void	create_fractol_img(t_param *param)
{
	double	x_win;
	double	y_win;
	int		n;

	x_win = 0;
	while (x_win < WIDTH)
	{
		y_win = 0;
		while (y_win < HEIGHT)
		{
			if (param->type == 0)
				n = is_within_set(0, 0, \
								scale(x_win, param->pos_x, param->zoom, 0), \
								scale(y_win, param->pos_y, param->zoom, 1));
			else if (param->type == 1)
				n = is_within_set(scale(x_win, param->pos_x, param->zoom, 0), \
								scale(y_win, param->pos_y, param->zoom, 1), \
								JULIA_COMPLEX_R, JULIA_COMPLEX_I);
			put_color_on_pixel(param->data, x_win, y_win, n);
			y_win++;
		}
		x_win++;
	}
}
