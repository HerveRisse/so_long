/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:58:36 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 21:33:24 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}

/*
int	main(int ac, char **av)
{
	size_t	size;

	if (ac != 3)
		return (0);
	size = ft_strlen(av[1]) + 1;
	printf("La taille de src est : %zu \n", size);
	printf("Le contenu og de src est : %s \n", av[1]);
	printf("Le contenu og de dst est : %s \n", av[2]);
	printf("ft_strlcpy :%zu \n", ft_strlcpy(av[2], av[1], size));
	printf("Le contenu de src est : %s \n", av[1]);
	printf("Le contenu de dst est : %s \n", av[2]);
}*/
