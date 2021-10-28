/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:21:23 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/28 15:07:02 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

t_flags	ft_init_flags(t_flags *flags)
{
	flags->lenght = 0;
	flags->sign = 0;
	return (*flags);
}

int	ft_to_format(t_flags *flags, const char *format, int i)
{
	if (format[i] == 'c')
		ft_wchar(va_arg(flags->args, int), flags);
	if (format[i] == 's')
		ft_wstr(va_arg(flags->args, char *), flags);
	if (format[i] == 'p')
		ft_wptr(va_arg(flags->args, unsigned long), flags);
	if (format[i] == 'd' || format[i] == 'i')
		ft_wint(va_arg(flags->args, int), flags);
	if (format[i] == 'u')
		ft_wunsint(va_arg(flags->args, unsigned int), flags);
	if (format[i] == 'x')
		ft_wlowerhex(va_arg(flags->args, unsigned int), flags);
	if (format[i] == 'X')
		ft_wupperhex(va_arg(flags->args, unsigned int), flags);
	if (format[i] == '%')
		flags->lenght += write(1, "%", 1);
	return (i + 1);
}

int	ft_printf(const char *format, ...)
{
	t_flags	*flags;
	int		i;

	i = 0;
	flags = (t_flags *)malloc(sizeof(t_flags));
	ft_init_flags(flags);
	va_start(flags->args, format);
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_to_format(flags, format, i + 1);
		else
		{
			write(1, &format[i], 1);
			flags->lenght += 1;
			i++;
		}
	}
	va_end(flags->args);
	free(flags);
	return (flags->lenght);
}
