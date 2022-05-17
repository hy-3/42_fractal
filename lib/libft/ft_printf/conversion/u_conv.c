/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:22:36 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/04/25 12:15:45 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

int	u_conv(va_list argptr)
{
	unsigned int	arg;

	arg = va_arg(argptr, unsigned int);
	return (cust_putnbr_unsigned_int(arg));
}
