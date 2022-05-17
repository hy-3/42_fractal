/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:40 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/17 15:09:01 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx_opengl_20191021/mlx.h"
#include "fractol.h"

int	key_hook(int keycode, t_param *param)
{
	if (keycode == ZOOMIN_KEY)
		param->zoom *= ZOOM_MOVE;
	if (keycode == ZOOMOUT_KEY)
		param->zoom /= ZOOM_MOVE;
	if (keycode == LEFT_KEY)
		param->pos_x -= AXIS_MOVE;
	if (keycode == RIGHT_KEY)
		param->pos_x += AXIS_MOVE;
	if (keycode == UP_KEY)
		param->pos_y += AXIS_MOVE;
	if (keycode == DOWN_KEY)
		param->pos_y -= AXIS_MOVE;
	create_mandelbrot_img(param);
	mlx_put_image_to_window(param->base->mlx, param->base->win, \
							param->data->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_param *param)
{
	if (button == MOUSE_UP_KEY)
		param->zoom *= ZOOM_MOVE;
	if (button == MOUSE_DOWN_KEY)
		param->zoom /= ZOOM_MOVE;
	create_mandelbrot_img(param);
	mlx_put_image_to_window(param->base->mlx, param->base->win, \
							param->data->img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_base	base;
	t_data	data;
	t_param	param;

	param.base = &base;
	param.data = &data;
	param.pos_x = 0;
	param.pos_y = 0;
	param.zoom = 1;
	base.mlx = mlx_init();
	base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "mandelbrot");
	data.img = mlx_new_image(base.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
									&data.line_length, &data.endian);
	create_mandelbrot_img(&param);
	mlx_put_image_to_window(base.mlx, base.win, data.img, 0, 0);
	mlx_key_hook(base.win, key_hook, &param);
	mlx_mouse_hook(base.win, mouse_hook, &param);
	mlx_loop(base.mlx);
	return (0);
}
