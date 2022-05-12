#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 500
# define INSIDE_COLOR 0x00000000
# define OUTSIDE_COLOR 0x00FFFFFF

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_base
{
	void	*mlx;
	void	*win;
}	t_base;

void	create_mandelbrot_img(t_data *data);

#endif