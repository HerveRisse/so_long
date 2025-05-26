/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:36:19 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 17:10:11 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char str[] = "hello there";

	printf("%s \n", str);
	ft_bzero((str + 4), 3);
	printf("%s \n", str);

	return (0);
}*/
