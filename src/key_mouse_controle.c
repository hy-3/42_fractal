/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_controle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:02:50 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/18 15:02:54 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	create_fractol_img(param);
	mlx_put_image_to_window(param->base->mlx, param->base->win, \
							param->data->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_param *param)
{
	if (button == 4)
		param->zoom *= ZOOM_MOVE;
	if (button == 5)
		param->zoom /= ZOOM_MOVE;
	create_fractol_img(param);
	mlx_put_image_to_window(param->base->mlx, param->base->win, \
							param->data->img, 0, 0);
	return (0);
}
