/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:12:49 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 17:02:33 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *dst, int c, size_t size)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char *)dst)[i] = (char)c;
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	str[] = "hello there";

	ft_memset(str, 48, 3);
	printf("%s\n", str);
	printf("%s\n", (char *)ft_memset((str + 3), 49, 4));
	printf("%s\n", (char *)ft_memset((str + 7), 50, 4));
	return (0);
}*/
// str[7] == *(str + 7)
// str + 7 == &str[7]
