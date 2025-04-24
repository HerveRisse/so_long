/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:07:53 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/19 09:50:20 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char    str[] = "hello there";
	char    str2[] = "holla there";
	size_t	n = 5;

	printf("%s\n", str);
	printf("%s\n", str2);
	printf("%s\n", (char *)ft_memcpy(str2, str, n));
	printf("%s\n", str);
	printf("%s\n", str2);
	return (0);
}*/
