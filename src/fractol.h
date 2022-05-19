/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:21 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/19 12:27:11 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/minilibx_opengl_20191021/mlx.h"
# include "../lib/libft/libft.h"

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 500
# define INSIDE_COLOR 0x00000000
# define OUTSIDE_COLOR 0x00FFFFFF
# define AXIS_MOVE 1
# define ZOOM_MOVE 2

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_base
{
	void	*mlx;
	void	*win;
}	t_base;

typedef struct s_param
{
	t_base	*base;
	t_data	*data;
	double	zoom;
	double	pos_x;
	double	pos_y;
	int		type;
	double	julia_complex_i;
	double	julia_complex_r;
}	t_param;

typedef struct s_args
{
	char	*arg1;
	char	*arg2;
}	t_args;

int		key_hook(int keycode, t_param *param);
int		mouse_hook(int button, int x, int y, t_param *param);
void	create_fractol_img(t_param *param);

#endif
