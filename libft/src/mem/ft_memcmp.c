/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:22:18 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/04 11:39:07 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	if (i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}
/*
int     main(void)
{
        char    str[] = "hello there !";
        char    str2[] = "holla there !";
        size_t  n = 5;

        printf("%s\n", str);
        printf("%s\n", str2);
        printf("%d\n", ft_memcmp(str, str2, n));
        printf("%d\n", ft_memcmp(str2, str, n));
        return (0);
}*/
