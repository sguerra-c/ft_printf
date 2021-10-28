/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:59:07 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/27 17:41:37 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_wptr(unsigned long x, t_flags *flags)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (x >= 16)
	{
		c = hex[x % 16];
		ft_wptr(x / 16, flags);
	}
	else
	{
		c = hex[x];
		write(1, "0x", 2);
		flags->lenght += 2;
	}
	write(1, &c, 1);
	flags->lenght += 1;
}
