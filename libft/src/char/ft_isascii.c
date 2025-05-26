/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:20:27 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 09:39:39 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	printf("%d \n", ft_isascii(-1));
	printf("%d \n", ft_isascii(0));
	printf("%d \n", ft_isascii(127));
	printf("%d \n", ft_isascii(128));
	return (0);
}*/
