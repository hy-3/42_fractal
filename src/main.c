/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:40 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/18 15:12:56 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mlx_with_fractol(char *str)
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
	base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "fractol");
	if (ft_strncmp(str, "mandelbrot", 11) == 0)
		param.type = 0;
	else if (ft_strncmp(str, "julia", 6) == 0)
		param.type = 1;
	data.img = mlx_new_image(base.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
									&data.line_length, &data.endian);
	create_fractol_img(&param);
	mlx_put_image_to_window(base.mlx, base.win, data.img, 0, 0);
	mlx_key_hook(base.win, key_hook, &param);
	mlx_mouse_hook(base.win, mouse_hook, &param);
	mlx_loop(base.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 \
				|| ft_strncmp(argv[1], "julia", 6) == 0)
			start_mlx_with_fractol(argv[1]);
		else
			ft_printf("Error: Give a parameter 'mandelbrot' or 'julia'\n");
	}
	else
		ft_printf("Error: Give a parameter 'mandelbrot' or 'julia'\n");
	return (0);
}
