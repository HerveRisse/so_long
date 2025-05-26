/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:34:07 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 21:36:20 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	return (ft_strcpy(cpy, s1));
}
/*
int main(void)
{
    const char *original = "Hello, World!";
    char *duplicate;

    duplicate = ft_strdup(original);
    if (duplicate == NULL)
    {
        printf("Échec de l'allocation mémoire\n");
        return (1);
    }

    printf("og : %s\n", original);
    printf("dup : %s\n", duplicate);

    free(duplicate);
    return (0);
}*/
