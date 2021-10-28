/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wunsint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:15:00 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/28 15:03:12 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_wunsint(unsigned int x, t_flags *flags)
{
	char	c;

	if (x >= 10)
	{
		c = (x % 10) + 48;
		ft_wunsint(x / 10, flags);
	}
	else
		c = x + 48;
	write(1, &c, 1);
	flags->lenght += 1;
}
