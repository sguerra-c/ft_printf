/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wupperhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:44:58 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/28 15:09:22 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_wupperhex(unsigned int x, t_flags *flags)
{
	char	c;
	char	*hex;

	hex = "0123456789ABCDEF";
	if (x >= 16)
	{
		c = hex[x % 16];
		ft_wupperhex(x / 16, flags);
	}
	else
		c = hex[x];
	write(1, &c, 1);
	flags->lenght += 1;
}
