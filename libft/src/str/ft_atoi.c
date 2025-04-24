/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:02:22 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/12 12:52:26 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	if (!str)
		return (0);
	i = 0;
	sign = 0;
	nb = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (sign % 2 == 1)
		nb = -nb;
	return (nb);
}
/*
int	main(void)
{
	char strerr[] = "   \t \r \f ---+--+1234ab567";
	char strneg[] = "   \t \r \f -1234ab567";
	char strpos[] = "   \t \r \f +1234ab567";
	printf("%d\n", ft_atoi(strerr));
	printf("%d\n", ft_atoi(strneg));
	printf("%d\n", ft_atoi(strpos));
	printf("%d\n", atoi(strerr));
	printf("%d\n", atoi(strneg));
	printf("%d\n", atoi(strpos));
	return (0);
}*/
