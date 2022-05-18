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
	create_fractol_img(param);
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
	create_fractol_img(param);
	mlx_put_image_to_window(param->base->mlx, param->base->win, \
							param->data->img, 0, 0);
	return (0);
}