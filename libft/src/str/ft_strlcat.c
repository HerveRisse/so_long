/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:55 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 16:31:58 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	t;

	if (!dst || !src)
		return (0);
	i = 0;
	j = 0;
	t = 0;
	while (dst[i])
		i++;
	while (src[t])
		t++;
	if (size <= i)
		return (size + t);
	t = t + i;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (t);
}
/*
int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("dst : %s \n", av[1]);
	printf("src : %s \n", av[2]);
	printf("cat : %zu \n", ft_strlcat(av[1], av[2], 8));
	printf("dst : %s \n", av[1]);
	printf("src : %s \n", av[2]);
	return (0);
}*/
