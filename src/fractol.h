/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:21 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/05/18 14:33:55 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/minilibx_opengl_20191021/mlx.h"
#include "../lib/libft/libft.h"

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 500
# define INSIDE_COLOR 0x00000000
# define OUTSIDE_COLOR 0x00FFFFFF
# define AXIS_MOVE 1
# define ZOOM_MOVE 2
# define ZOOMIN_KEY 34
# define ZOOMOUT_KEY 31
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125
# define MOUSE_UP_KEY 4
# define MOUSE_DOWN_KEY 5
# define ESCAPE_KEY 53

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
	int		set;
}	t_param;

int		key_hook(int keycode, t_param *param);
int		mouse_hook(int button, int x, int y, t_param *param);
void	create_fractol_img(t_param *param);

#endif
