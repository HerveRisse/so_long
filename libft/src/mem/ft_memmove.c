/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:12:48 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 22:14:30 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dst);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		}
		return (dst);
	}
}
/*
int     main(void)
{
		char    str[] = "hello there !";
		char    str2[] = "holla there !";
		size_t  n = 5;

		printf("%s\n", str);
		printf("%s\n", str2);
		printf("%s\n", (char *)ft_memmove(str2, str, n));
		printf("%s\n", str2);
		printf("%s\n", (char *)ft_memmove((str + 3), str, n));
		return (0);
}*/
