/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:56:17 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/05 11:03:13 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int main(void)
{
    int number = 42;
    t_list *node = ft_lstnew(&number);

    if (node)
    {
        printf("Content: %d\n", *(int *)node->content);
        printf("Next: %p\n", (void *)node->next);
    }

    free(node);
    return (0);
}*/
