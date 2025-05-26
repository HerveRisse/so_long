/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:44:55 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 09:18:28 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int	main(void)
{
	printf("%d \n", ft_isalpha(64));
	printf("%d \n", ft_isalpha('a'));
	printf("%d \n", ft_isalpha(91));
	printf("%d \n", ft_isalpha('z'));
	printf("%d \n", ft_isalpha(96));
	printf("%d \n", ft_isalpha('A'));
	printf("%d \n", ft_isalpha(123));
	printf("%d \n", ft_isalpha('Z'));
	printf("%d \n", ft_isdigit(47));
	printf("%d \n", ft_isdigit('0'));
	printf("%d \n", ft_isdigit(58));
	printf("%d \n", ft_isdigit('9'));
	return (0);
}*/
