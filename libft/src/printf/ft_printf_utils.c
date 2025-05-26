/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:35:30 by hrisse            #+#    #+#             */
/*   Updated: 2025/02/11 07:36:01 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, len);
		str++;
	}
}

void	ft_putnbr_base(unsigned long n, char *base, int base_len, int *len)
{
	if (n >= (unsigned long)base_len)
		ft_putnbr_base(n / base_len, base, base_len, len);
	ft_putchar(base[n % base_len], len);
}

void	ft_putnbr(long n, int *len)
{
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	ft_putnbr_base(n, "0123456789", 10, len);
}
