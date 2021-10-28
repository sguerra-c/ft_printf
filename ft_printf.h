/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:16:51 by sguerra-          #+#    #+#             */
/*   Updated: 2021/09/28 15:11:08 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	va_list	args;
	int		lenght;
	int		sign;
}	t_flags;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
void	ft_wint(int x, t_flags *flags);
void	ft_wptr(unsigned long x, t_flags *flags);
void	ft_wchar(int x, t_flags *flags);
void	ft_wstr(char *str, t_flags *flags);
void	ft_wunsint(unsigned int x, t_flags *flags);
void	ft_wlowerhex(unsigned int x, t_flags *flags);
void	ft_wupperhex(unsigned int x, t_flags *flags);

#endif
