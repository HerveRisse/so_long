/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:14:42 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 21:43:24 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*p;

	if (size != 0 && nb > SIZE_MAX / size)
		return (NULL);
	p = malloc(nb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nb * size);
	return (p);
}
/*
int	main(void)
{
	int	*arr;
	size_t	nb = 5;
	size_t	size = sizeof(int);
	size_t	i;

	i = 0;
	arr = (int*)ft_calloc(nb, size);
	while (i < nb)
	{
		printf("arr[%zu] = %d \n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/
