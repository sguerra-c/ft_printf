/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:35:54 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/27 17:42:30 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_wstr(char *str, t_flags *flags)
{
	if (str == NULL)
		flags->lenght += write(1, "(null)", 6);
	else
		flags->lenght += write(1, str, ft_strlen(str));
}
