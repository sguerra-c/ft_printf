/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:25:00 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/27 17:39:47 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_wint(int x, t_flags *flags)
{
	char	c;

	if (x == -2147483648 && ++flags->lenght)
		ft_wint(-214748364, flags);
	else
	{
		if (x < 0 && ++flags->sign)
			x *= -1;
		if (x >= 10)
		{
			c = (x % 10) + 48;
			ft_wint(x / 10, flags);
		}
		else
		{
			c = x + 48;
			if (flags->sign == 1 && ++flags->lenght)
				write(1, "-", 1);
		}
		write(1, &c, 1);
		flags->lenght += 1;
		flags->sign = 0;
		return ;
	}
	write(1, "8", 1);
}
