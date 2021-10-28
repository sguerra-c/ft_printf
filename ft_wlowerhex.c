/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlowerhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:49:49 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/27 17:43:09 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_wlowerhex(unsigned int x, t_flags *flags)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (x >= 16)
	{
		c = hex[x % 16];
		ft_wlowerhex(x / 16, flags);
	}
	else
		c = hex[x];
	write(1, &c, 1);
	flags->lenght += 1;
}
