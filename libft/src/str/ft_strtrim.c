/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:14:44 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 22:17:19 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*to_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		in_set;

	if (!s1 || !set)
		return (NULL);
	in_set = 0;
	i = 0;
	j = 0;
	while (s1[i])
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i++;
	}
	return ((char *) s1 + i);
}

static char	*to_end(char const *s1, char const *set, char const *start)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 0;
	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1 + i >= start)
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i--;
	}
	if (s1 + i < start)
		return ((char *) start);
	return ((char *) s1 + i);
}

static char	*trimmed_str(char const *start, char const *end)
{
	char	*new;
	size_t	i;

	if (!start || !end)
		return (NULL);
	new = malloc(sizeof(char) * (end - start + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		new[i] = start[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = to_start(s1, set);
	end = to_end(s1, set, s1);
	if (!s1[0] || end < start)
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
	}
	else
		new = trimmed_str(start, end);
	if (!new)
		return (NULL);
	return (new);
}
/*
int	main(void)
{
	char	*s1 = "--**C Programming**--";
	char	*set = "-*";
	char	*res = ft_strtrim(s1, set);
	
	printf("\nog : '%s'\n", s1);
	printf("set : '%s'\n", set);
	printf("res : '%s'\n", res);

	free(res);
	return (0);
}*/
