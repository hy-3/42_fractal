#include <stdio.h>



#include "../lib/minilibx_macos/mlx.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_param
{
	t_data	*data;
	t_vars	*var;
	int 	i;
}	t_param;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render_next_frame(t_param	*param)
{
	t_data	img;

	img.img = mlx_new_image(param->var->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int i = 100;
	while (i <= 500)
	{
		my_mlx_pixel_put(&img, i + param->i, 100, 0x00FFFFFF);
		my_mlx_pixel_put(&img, 100 + param->i, i, 0x00FFFFFF);
		my_mlx_pixel_put(&img, 500 + param->i, i, 0x00FFFFFF);
		my_mlx_pixel_put(&img, i + param->i, 500, 0x00FFFFFF);
		i++;
	}
	mlx_put_image_to_window(param->var->mlx, param->var->win, img.img, 0, 0);
	param->i += 1;
	//DELETE WINDOW
	return (0);
}

int	mouse_hook(int keycode, t_vars *var, t_data img)
{
	if (keycode == 1)
		printf("hook called \n");
	return (0);
}

int	main(void)
{
	t_vars	var;
	t_data	img;
	t_param	param;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "temp");

	img.img = mlx_new_image(var.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// int i = 100;
	// while (i <= 500)
	// {
	// 	my_mlx_pixel_put(&img, i, 100, 0x00FFFFFF);
	// 	my_mlx_pixel_put(&img, 100, i, 0x00FFFFFF);
	// 	my_mlx_pixel_put(&img, 500, i, 0x00FFFFFF);
	// 	my_mlx_pixel_put(&img, i, 500, 0x00FFFFFF);
	// 	i++;
	// }
	// i = 300;
	// while (i <= 700)
	// {
	// 	my_mlx_pixel_put(&img, i, 300, 0x0000FFFF);
	// 	my_mlx_pixel_put(&img, 300, i, 0x0000FFFF);
	// 	my_mlx_pixel_put(&img, 700, i, 0x0000FFFF);
	// 	my_mlx_pixel_put(&img, i, 700, 0x0000FFFF);
	// 	i++;
	// }
	// mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);

	mlx_mouse_hook(var.win, mouse_hook, &var);

	param.var = &var;
	param.data = &img;
	param.i = 0;
	mlx_loop_hook(var.mlx, render_next_frame, &param);
	mlx_loop(var.mlx);

	return (0);
}
