/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:26:20 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/04/23 12:20:14 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(char c, va_list argptr)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = c_conv(argptr);
	if (c == 's')
		res = s_conv(argptr);
	if (c == 'p')
		res = p_conv(argptr);
	if (c == 'd' || c == 'i')
		res = d_i_conv(argptr);
	if (c == 'u')
		res = u_conv(argptr);
	if (c == 'x')
		res = x_conv(argptr, 0);
	if (c == 'X')
		res = x_conv(argptr, 1);
	if (c == '%')
		res = cust_putchar('%');
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	argptr;

	i = 0;
	res = 0;
	va_start(argptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (is_char_match(format[i], CONVERSION) == 1)
				res += convert(format[i++], argptr);
		}
		if (format[i] == '\0')
			break ;
		if (format[i] != '%')
			res += cust_putchar(format[i++]);
	}
	va_end(argptr);
	return (res);
}
