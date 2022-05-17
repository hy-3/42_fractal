#include "../lib/minilibx_opengl_20191021/mlx.h"
#include "fractol.h"

int	main(void)
{
	t_base	base;
	t_data	data;

	base.mlx = mlx_init();
	base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "mandelbrot");
	data.img = mlx_new_image(base.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	create_mandelbrot_img(&data);
	mlx_put_image_to_window(base.mlx, base.win, data.img, 0, 0);
	mlx_loop(base.mlx);
	return (0);
}
