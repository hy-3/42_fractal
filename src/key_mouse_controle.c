/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_controle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:02:50 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/19 12:36:41 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key_hook(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 34)
		param->zoom *= ZOOM_MOVE;
	else if (keycode == 31)
		param->zoom /= ZOOM_MOVE;
	else if (keycode == 123)
		param->pos_x -= AXIS_MOVE / param->zoom;
	else if (keycode == 124)
		param->pos_x += AXIS_MOVE / param->zoom;
	else if (keycode == 126)
		param->pos_y += AXIS_MOVE / param->zoom;
	else if (keycode == 125)
		param->pos_y -= AXIS_MOVE / param->zoom;
	create_fractal_img(param);
	mlx_put_image_to_window(param->base->mlx, param->base->win, \
							param->data->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_param *param)
{
	x = 0;
	y = 0;
	if (button == 4)
		param->zoom *= ZOOM_MOVE;
	if (button == 5)
		param->zoom /= ZOOM_MOVE;
	create_fractal_img(param);
	mlx_put_image_to_window(param->base->mlx, param->base->win, \
							param->data->img, x, y);
	return (0);
}
