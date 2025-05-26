/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:52:34 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 21:49:03 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int     main(void)
{
        char    str[] = "hello there !";
        char    str2[] = "holla there !";
        char	c = 'o';
        char    f = 'e';

        printf("%s\n", str);
        printf("%s\n", str2);
        printf("%s\n", (char *)ft_strrchr(str, c));
        printf("%s\n", (char *)ft_strrchr(str2, c));
        printf("%s\n", (char *)ft_strrchr(str, f));
        printf("%s\n", (char *)ft_strrchr(str2, f));
        return (0);
}*/
