/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:58:48 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 22:01:23 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	current = start;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		if (!current->next)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (start);
}
/*
void *x_two(void *content)
{
    int *new_value = malloc(sizeof(int));
    if (!new_value)
        return (NULL);
    *new_value = (*(int *)content) * 2;
    return (new_value);
}

void del(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list = NULL;
    int a = 1, b = 2, c = 3;

    ft_lstadd_back(&list, ft_lstnew(&a));
    ft_lstadd_back(&list, ft_lstnew(&b));
    ft_lstadd_back(&list, ft_lstnew(&c));

    t_list *tmp = list;
    while (tmp)
    {
        printf(" %d", *(int *)(tmp->content));
        tmp = tmp->next;
    }

    t_list *mapped_list = ft_lstmap(list, x_two, del);

    tmp = mapped_list;
    while (tmp)
    {
        printf(" %d", *(int *)(tmp->content));
        tmp = tmp->next;
    }

    ft_lstclear(&mapped_list, del);
    return (0);
}*/
