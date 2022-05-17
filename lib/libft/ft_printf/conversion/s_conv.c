/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:22:30 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/04/25 12:15:41 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

int	s_conv(va_list argptr)
{
	char	*arg;
	int		i;

	arg = va_arg(argptr, char *);
	if (arg == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		i++;
	}
	return (i);
}
