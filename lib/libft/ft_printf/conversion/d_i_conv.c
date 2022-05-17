/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:22:54 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/04/25 12:15:34 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

int	d_i_conv(va_list argptr)
{
	int	arg;

	arg = va_arg(argptr, int);
	return (cust_putnbr_int(arg));
}
