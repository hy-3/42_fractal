/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:23:20 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/04/25 12:15:48 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

int	hex_l(unsigned int i, int count)
{
	if (i < 16)
	{
		write(1, &HEX_L[i], 1);
		return (++count);
	}
	else
	{
		count = hex_l(i / 16, ++count);
		write(1, &HEX_L[i % 16], 1);
	}
	return (count);
}

int	hex_c(unsigned int i, int count)
{
	if (i < 16)
	{
		write(1, &HEX_C[i], 1);
		return (++count);
	}
	else
	{
		count = hex_c(i / 16, ++count);
		write(1, &HEX_C[i % 16], 1);
	}
	return (count);
}

int	x_conv(va_list argptr, int flag)
{
	unsigned int	arg;
	int				res;

	arg = va_arg(argptr, unsigned int);
	if (flag == 0)
		res = hex_l(arg, 0);
	if (flag == 1)
		res = hex_c(arg, 0);
	return (res);
}
