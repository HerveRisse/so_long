/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:28:40 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 11:52:41 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	printf("5 : %zu\n", ft_strlen("hello"));
	printf("22 : %zu\n", ft_strlen("hello, comment ca va ?"));
	return (0);
}*/
