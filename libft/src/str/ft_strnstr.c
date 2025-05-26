/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:50:07 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 21:50:13 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *) big);
	n = ft_strlen(little);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (j == n)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
    printf("Résultat : %s\n", ft_strnstr("hello holla hallo", "hallo", 17));
    return (0);
}*/
