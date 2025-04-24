/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:49:19 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 08:08:20 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include"libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
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
	return (0);
}*/
