/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:25:19 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/04/25 12:18:50 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define CONVERSION "cspdiuxX%"
# define HEX_L "0123456789abcdef"
# define HEX_C "0123456789ABCDEF"

// Main
int				ft_printf(const char *format, ...);

// Conversion
int				c_conv(va_list argptr);
int				s_conv(va_list argptr);
int				p_conv(va_list argptr);
int				d_i_conv(va_list argptr);
int				u_conv(va_list argptr);
int				x_conv(va_list argptr, int flag);

// Util
int				is_char_match(char c, char *list);
int				base_ten_power(int n);
int				cust_putnbr_int(int n);
int				cust_putnbr_unsigned_int(unsigned int n);
int				cust_putchar(char c);

#endif
