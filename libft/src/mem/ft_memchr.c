/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:27:21 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/19 10:35:22 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
int     main(void)
{
        char    str[] = "hello there !";
        char    str2[] = "holla there !";
        size_t  n = 5;

        printf("%s\n", str);
        printf("%s\n", str2);
        printf("%s\n", (char *)ft_memchr(str, 'o', n));
        printf("%s\n", (char *)ft_memchr(str2, 'o', n));
	printf("%s\n", (char *)ft_memchr(str2, 'z', n));
        return (0);
}*/
