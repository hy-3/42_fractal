/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:40 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/19 15:52:45 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia_params(t_param *param, char *num)
{
	param->type = 1;
	if (ft_strncmp(num, "1", 2) == 0)
	{
		param->julia_complex_r = 0;
		param->julia_complex_i = 0;
	}
	else if (ft_strncmp(num, "2", 2) == 0)
	{
		param->julia_complex_r = -0.759375;
		param->julia_complex_i = 0.139826;
	}
	else if (ft_strncmp(num, "3", 2) == 0)
	{
		param->julia_complex_r = -0.767679;
		param->julia_complex_i = 0.001753;
	}
	else
	{
		ft_printf("Choose from 1 to 3 as a second parameter for Julia set\n");
		exit(0);
	}
}

void	start_mlx_with_fractol(t_args *args)
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
	if (ft_strncmp(args->arg1, "mandelbrot", 11) == 0)
		param.type = 0;
	else if (ft_strncmp(args->arg1, "julia", 6) == 0)
		set_julia_params(&param, args->arg2);
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
	t_args	args;

	if (argc == 2 || argc == 3)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		{
			args.arg1 = argv[1];
			start_mlx_with_fractol(&args);
		}
		else if (ft_strncmp(argv[1], "julia", 6) == 0)
		{
			args.arg1 = argv[1];
			args.arg2 = "1";
			if (argc == 3)
				args.arg2 = argv[2];
			start_mlx_with_fractol(&args);
		}
		else
			ft_printf("Error: Give a parameter 'mandelbrot' or 'julia'\n");
	}
	else
		ft_printf("Error: Give a parameter 'mandelbrot' or 'julia'\n");
	return (0);
}
