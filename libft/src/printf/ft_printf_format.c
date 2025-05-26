/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:26:35 by hrisse            #+#    #+#             */
/*   Updated: 2025/02/11 10:49:23 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_p(va_list args, int *len)
{
	unsigned long	t;

	t = va_arg(args, unsigned long);
	if (t == 0)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		ft_putnbr_base(t, "0123456789abcdef", 16, len);
	}
}

void	ft_handle_format(char format, va_list args, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'p')
	{
		ft_handle_p(args, len);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10, len);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 16, len);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16, len);
	else if (format == '%')
		ft_putchar('%', len);
}
