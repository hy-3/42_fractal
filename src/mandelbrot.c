#include "fractol.h"

int	mandelbrot(double c_re, double c_im)
{
	double	x;
	double	y;
	double	x_tmp;
	int	n;

	x = 0;
	y = 0;
	n = 0;
	while ((x*x + y*y) <= 4 && n < (int)MAX_ITER)
	{
		x_tmp = x*x - y*y + c_re;
		y = 2*x*y + c_im;
		x = x_tmp;
		n++;
	}
	return (n);
}
